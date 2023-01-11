#include "Application.h"
#include "ModuleUI.h"
#include "GameWindow.h"
#include "ModuleRenderer3D.h"

ModuleUI::ModuleUI(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleUI::~ModuleUI()
{
}

bool ModuleUI::Start()
{
	return false;
}

update_status ModuleUI::PreUpdate(float dt)
{
	update_status ret = UPDATE_CONTINUE;

	if (App->gameState == GameState::PLAY)
	{
		
		float MousePosX = App->input->GetMouseX();
		float MousePosY = App->input->GetMouseY();
		int widthGWindow = SDL_GetWindowSurface(App->window->window)->w;
		int heightGWindow = SDL_GetWindowSurface(App->window->window)->h;
		
		float4 GameScreen;
		/*GameScreen = {GameWindows::sizeWindScn.x}
		//float4 GameWindow = App.
		if (MousePosX)
		{

		}*/
	}

	return ret;
}

update_status ModuleUI::Update(float dt)
{
	update_status ret = UPDATE_CONTINUE;

	return ret;
}

update_status ModuleUI::PostUpdate(float dt)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

	glPushMatrix();

	App->renderer3D->BindCameraBuffer(App->renderer3D->mainGameCamera);

	Frustum frustum;
	frustum.pos = float3::zero;
	frustum.front = float3::unitZ; //COGED EL FRONT DE LA CAMARA DE JUEGO
	frustum.up = float3::unitY; //COGED EL UP DE LA CAMARA DE JUEGO
	frustum.type = OrthographicFrustum;
	//frustum.orthographicHeight = App->renderer3D->mainGameCamera->size.y; //PONER EL TAMAÑO DEL VIEWPORT DONDE QUERAIS PINTAR
	//frustum.orthographicWidth = App->renderer3D->mainGameCamera->size.x; //PONER EL TAMAÑO DEL VIEWPORT DONDE QUERAIS PINTAR
	frustum.nearPlaneDistance = 0.1;
	frustum.farPlaneDistance = 1000.f;

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(frustum.ProjectionMatrix().Transposed().ptr());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	update_status ret = UPDATE_CONTINUE;
	return ret;
}

bool ModuleUI::CleanUp()
{
	return false;
}