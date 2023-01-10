#include "ComponentUICamera.h"
#include "GameObject.h"
#include "Transform.h"
#include "imgui.h"
#include "Application.h"
#include "ModuleMesh.h"

UICameraComponent::UICameraComponent()
{
	//Component
	type = ComponentType::CAMERA;
	containerParent = nullptr;

	//Frustum
	frustum.type = OrthographicFrustum;
	frustum.nearPlaneDistance = nearDistance;
	frustum.farPlaneDistance = farDistance; //inspector
	frustum.front = float3::unitZ;
	frustum.up = float3::unitY;
	frustum.horizontalFov = 2.0f * atanf(tanf(frustum.verticalFov / 2.0f) * 1.7f); // 16:9 ~= 1,77777...
	frustum.pos = float3(0, 0, 0);

}

UICameraComponent::~UICameraComponent()
{
	if (isMainCamera) Application::GetInstance()->renderer3D->SetMainCamera(nullptr);

	glDeleteFramebuffers(1, &UIcameraBuffer);
	glDeleteFramebuffers(1, &UIframeBuffer);
	glDeleteFramebuffers(1, &UIrenderObjBuffer);

}

void UICameraComponent::PrintInspector()
{

}

void UICameraComponent::Update()
{
	if (containerParent == nullptr) return;

	
	float4x4 m = containerParent->transform->getGlobalMatrix();
	frustum.up = m.RotatePart().Col(1).Normalized();
	frustum.front = m.RotatePart().Col(2).Normalized();
}



float* UICameraComponent::GetViewMatrix()
{
	viewMatrix = frustum.ViewMatrix();
	viewMatrix.Transpose();
	return viewMatrix.ptr();
}

float* UICameraComponent::GetProjetionMatrix()
{
	projectionMatrix = frustum.ProjectionMatrix();
	projectionMatrix.Transpose();
	return projectionMatrix.ptr();
}

bool UICameraComponent::IsInsideFrustum(Mesh* mesh)
{
	float3 boxPoints[8];
	Plane frustumPlanes[6];

	mesh->Global_AABB_box.GetCornerPoints(boxPoints);
	frustum.GetPlanes(frustumPlanes);

	//Check all frustum planes
	for (size_t i = 0; i < 6; i++)
	{
		int p = 0;

		//Check all box points to each frustum plane
		for (size_t j = 0; j < 8; j++)
		{
			if (frustumPlanes[i].IsOnPositiveSide(boxPoints[j]))
				p++;
		}

		//Check if all points are outside
		if (p == 8) {
			//All points outside one of the planes -> outside frustum
			return false;
		}
	}

	//AABB box is at least partially inside frustum
	return true;
}
