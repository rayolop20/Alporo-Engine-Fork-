#pragma once
#include "Component.h"
#include "MathGeoLib.h"

struct Mesh;
struct CameraComponent;

class UICameraComponent : public Component
{
public:
	UICameraComponent();
	~UICameraComponent();

	void PrintInspector();
	void Update();

	float* GetViewMatrix();
	float* GetProjetionMatrix();

	bool IsInsideFrustum(Mesh* mesh);

	Frustum frustum;
	float3 reference;

	int typeCameraSelected = 0;

	float farDistance = 500.0f;
	float nearDistance = 0.1f;

	bool isMainCamera = false;

	//unsigned int UIcameraBuffer;
	//unsigned int UIframeBuffer;
	CameraComponent* UICam;
	float2 size;
private:
	float4x4 viewMatrix;
	float4x4 projectionMatrix;

	unsigned int UIrenderObjBuffer;
};