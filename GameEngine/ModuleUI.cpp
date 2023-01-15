#include "Application.h"
#include "ModuleUI.h"
#include "GameWindow.h"
#include "ModuleMesh.h"
#include "ModuleRenderer3D.h"
#include "ComponentCamera.h"
#include "ButtonComponent.h"

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

	}


	return ret;
}

update_status ModuleUI::Update(float dt)
{
	update_status ret = UPDATE_CONTINUE;

	MousePos.x = App->input->GetMouseX();
	MousePos.y = App->input->GetMouseY();


	if (MousePos.x > GameWindows::vMin.x && MousePos.y > GameWindows::vMin.y && MousePos.x < GameWindows::vMax.x && MousePos.y < GameWindows::vMax.y)
	{
		GetComponentype(App->hierarchy->selectedGameObj);

		//if (App->hierarchy->selectedGameObj->components)
		//{
		//
		//}
	
	}



	return ret;
}

update_status ModuleUI::PostUpdate(float dt)
{

	update_status ret = UPDATE_CONTINUE;
	return ret;
}

bool ModuleUI::CleanUp()
{
	return false;
}

void ModuleUI::BindUIBuffer()
{
	//App->renderer3D->BindCameraBuffer(App->renderer3D->mainGameCamera);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(App->renderer3D->mainGameCamera->GetProjetionMatrix());

	glMatrixMode(GL_MODELVIEW);
	//glLoadMatrixf(App->renderer3D->mainGameCamera->GetViewMatrix());
	glPushMatrix();
	App->renderer3D->mainGameCamera->frustum.pos = float3::zero;
	App->renderer3D->mainGameCamera->frustum.front = float3::unitZ;
	App->renderer3D->mainGameCamera->frustum.up = float3::unitY;
	App->renderer3D->mainGameCamera->frustum.type = OrthographicFrustum;
	App->renderer3D->mainGameCamera->frustum.orthographicHeight = GameWindows::vMax.y - GameWindows::vMin.y; //GameWindows::vMin, GameWindows::vMax
	App->renderer3D->mainGameCamera->frustum.orthographicWidth =  GameWindows::vMax.x - GameWindows::vMin.x;
	App->renderer3D->mainGameCamera->frustum.nearPlaneDistance = 0.1;
	App->renderer3D->mainGameCamera->frustum.farPlaneDistance = 1000.f;


	DrawColor();
	App->meshRenderer->RenderUIWindow();

	glEnable(GL_DEPTH_TEST);
	glPopMatrix();


	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ModuleUI::GetComponentype(GameObject* GOSelected)
{

	int mouse_x, mouse_y;
	Uint32 mouse_state = SDL_GetMouseState(&mouse_x, &mouse_y);

	if (GOSelected != nullptr)
	{
		if (GOSelected->type == GameObjectType::UI)
		{
			for (size_t i = 0; i < GOSelected->components.size(); ++i)
			{
				switch (GOSelected->components[i]->type)
				{
				case ComponentType::UI_BUTTON:

				{
						if (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT) && GOSelected->UISType == UIState::FOCUSED)
						{
							GOSelected->UISType = UIState::ENABLE;
						}

						if (GOSelected->UISType == UIState::DISABLED && GOSelected->UISType != UIState::ENABLE)
						{
							GOSelected->UISType = UIState::FOCUSED;
						}

				}
					break;
				case ComponentType::UI_CANVA:
				{
					if (GOSelected->UISType == UIState::DISABLED && App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_REPEAT)
					{
						GOSelected->UISType = UIState::PRESSED;
					}
					if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_UP)
					{
						GOSelected->UISType  = UIState::DISABLED;
					}

				}
					break;
				case ComponentType::UI_CHECKBOX:
				{
					if (GOSelected->UISType == UIState::DISABLED && App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
					{
						GOSelected->UISType = UIState::ENABLE;
					}

					else if (GOSelected->UISType == UIState::ENABLE && App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
					{
						GOSelected->UISType = UIState::DISABLED;
					}
				}
					break;
				case ComponentType::UI_INPUTBOX:
					{
						if (GOSelected->UISType == UIState::DISABLED && App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
						{
							GOSelected->UISType  = UIState::PRESSED;
						}

						else if (GOSelected->UISType == UIState::PRESSED && App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
						{
							GOSelected->UISType = UIState::DISABLED;
						}

					}

					break;
				default:
					break;
				}

				//if (GOSelected->components[i]->type != ComponentType::UI_BUTTON)
				//{
				//	for (size_t j = 0; j < App->meshRenderer->meshes.size(); j++)
				//	{
				//		if (GOSelected->components[i]->type != ComponentType::UI_CANVA)
				//		{
				//			App->meshRenderer->meshes[i]->myGameObject->UISType = UIState::DISABLED;
				//		}
				//
				//	}
				//}

			}
		}
	}

	if (GOSelected == nullptr) {
		for (size_t i = 0; i < App->meshRenderer->meshes.size(); i++)
		{
				//App->meshRenderer->meshes[i]->myGameObject->UISType = UIState::DISABLED;
		}
	}
}

void ModuleUI::DrawColor()
{
	Mesh* Ui;
	for (int i = 0; i < App->meshRenderer->meshes.size(); i++) {

		Ui = App->meshRenderer->meshes[i];

		if (Ui->myGameObject->type == GameObjectType::UI)
		{
			for (size_t i = 0; i < Ui->myGameObject->components.size(); ++i)
			{
				switch (Ui->myGameObject->components[i]->type)
				{
				case ComponentType::UI_BUTTON:
					if (Ui->myGameObject->UISType == UIState::DISABLED)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(1, 1, 1, 1);
						Ui->Render();
					}
					if (Ui->myGameObject->UISType == UIState::FOCUSED)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(0, 1, 0, 1);
						Ui->Render();
					}

					if (Ui->myGameObject->UISType == UIState::ENABLE)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(1, 1, 1, 1);
						Ui->Render();
					}
					break;
				case ComponentType::UI_CANVA:
					//quan el mouse picking vagi be aqui va Un if Amb un SDL Click Esquerra
					if (Ui->myGameObject->UISType == UIState::DISABLED)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(1, 1, 1, 1);
						Ui->Render();
					}
					if (Ui->myGameObject->UISType == UIState::PRESSED)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(0, 0, 1, 1);
						Ui->Render();
					}
					break;
				case ComponentType::UI_INPUTBOX:
					//quan el mouse picking vagi be aqui va Un if Amb un SDL Click Esquerra
					if (Ui->myGameObject->UISType == UIState::DISABLED)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(1, 1, 1, 1);
						Ui->Render();
					}
					if (Ui->myGameObject->UISType == UIState::PRESSED)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(0, 0, 1, 1);
						Ui->Render();
					}
					break;
				case ComponentType::UI_CHECKBOX:
					//quan el mouse picking vagi be aqui va Un if Amb un SDL Click Esquerra
					if (Ui->myGameObject->UISType == UIState::DISABLED)
					{
						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(1, 1, 1, 1);
						Ui->Render();
						Ui->textureID = Application::GetInstance()->textures->LoadTexture("Assets/CheckBox_0.png");
					}
					if (Ui->myGameObject->UISType == UIState::ENABLE)
					{

						glAlphaFunc(GL_GREATER, 0.5);
						glEnable(GL_ALPHA_TEST);
						glColor4f(1, 0, 1, 1);
						Ui->Render();
						Ui->textureID = Application::GetInstance()->textures->LoadTexture("Assets/CheckBox_1.png");
					}
					/*
					if (App->meshRenderer->meshes[i]->myGameObject->UISType == UIState::DISABLED && /*App->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_UP App->meshRenderer->meshes[i]->myGameObject->UISType != UIState::ENABLE)
					{
						App->meshRenderer->meshes[i]->myGameObject->UISType = UIState::FOCUSED;
					}
					*/
					break;
				default:
					break;
				}
			}

		}
		glDisable(GL_ALPHA_TEST);
		glColor3f(255, 255, 255);
	}
}
