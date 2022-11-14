#pragma once
#include "Module.h"
#include "Globals.h"
#include "imgui.h"

#include "MathGeoLib.h"

#include "Logs.h"

#include "GameObject.h"

#include <string>
#include <vector>

class ModuleDummy : public Module
{
public:

	ModuleDummy(Application* app, bool start_enabled = true);
	~ModuleDummy();

	bool Start();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();

	/*void winPrimitive();*/


private:
	std::string word = "hola";
	GameObject* testObject = nullptr;
	GameObject* testObject2 = nullptr;
	GameObject* testObject3 = nullptr;

	GameObject* testObject9 = nullptr;
	GameObject* testObject8 = nullptr;
	GameObject* testObject7 = nullptr;

	float4 patata;
};