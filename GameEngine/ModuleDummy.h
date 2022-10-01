#pragma once
#include "Module.h"
#include "Globals.h"
#include "glmath.h"
#include "imgui.h"

#include "hstring.h"

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

	void PrintDebug(char* a);


private:

	ImVec4* colorEdit2;
	float colorEdit[4] = { 0.4f, 0.7f, 0.0f, 0.5f };

	char par[32] = "qwertyuioplkjhgfdsazxcvbnmpoiuy";

	bool IsWireframe = false;
	bool infoWind = false;
};