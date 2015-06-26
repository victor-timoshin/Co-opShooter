#include "../Inc/PlayScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
	Core::System::LWINDOWDESC windowDesc;
	windowDesc.proc = Core::System::ProcessEvent;
	windowDesc.mode = Core::System::WINDOWMODE::Windowed;
	windowDesc.title = "Demo";
	windowDesc.clientWidth = WINDOW_WIDTH;
	windowDesc.clientHeight = WINDOW_HEIGHT;

	Core::System::IWindowBase* window = 0L;
	window = Core::System::RegisterWindow(windowDesc);
	window->Create();
	window->Update();
	window->Show();

	Render::IRenderSystemBase* renderSystem = 0L;
	renderSystem = Render::RegisterRenderSystem();
	renderSystem->CreateDevice("GapiOpenGL_Win32_Debug", window);

	Scene::ISceneGraphBase* sceneGraph = 0L;
	sceneGraph = Scene::RegisterSceneGraph(renderSystem);

	Scene::ISceneManagementBase* sceneManagement = 0L;
	sceneManagement = Scene::RegisterSceneManagement();
	sceneManagement->ChangeState(PlayScene::Instance(), sceneGraph);

	while (window->MainLoop(false))
	{
		sceneManagement->FrameStarted(0.0f);
		renderSystem->FrameDrawed();
		sceneManagement->FrameEnded();
	}

	SAFE_DELETE(sceneManagement);
	SAFE_DELETE(sceneGraph);
	SAFE_DELETE(renderSystem);
	SAFE_DELETE(window);

	return 0;
}