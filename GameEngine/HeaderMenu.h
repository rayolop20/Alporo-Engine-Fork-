#include "Application.h"

using namespace std;

class HMenu
{
public:

	static void PrintMenu();
	static void ThemeStylePopUp();
	static void ThemeStyleMenuBar();
	static void ThemeStyleWind();

	static bool quit;

	static bool openInspector;
	static bool openConsole;
	static bool openConfig;
	static bool openHierarchy;

	static bool styleSelectD;
	static bool styleSelectL;
	static bool styleSelectSD;
	static bool styleSelectP;
	static int colorStyle;

private:
	static float colorWind[4];
	static float colorText[4];


};