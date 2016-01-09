#include "../Inc/State/PlayScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
	Core::IFrameworkBase* framework = nullptr;
	framework = Core::RegisterFramework();
	framework->Initialize(PlayScene::GetInstancePtr());
	framework->Run();
	framework->Shutdown();

	return 0;
}