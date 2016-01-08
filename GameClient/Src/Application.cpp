#include "../Inc/State/PlayScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
	System::WINDOW_DESCRIPTION windowDesc;
	windowDesc.proc = System::ProcessEvent;
	windowDesc.mode = System::WINDOW_MODE::Windowed;
	windowDesc.title = "Demo";
	windowDesc.width = SCREEN_WIDTH;
	windowDesc.height = SCREEN_HEIGHT;

	System::IWindowBase* window = nullptr;
	window = System::RegisterWindow(windowDesc);
	window->Create();
	window->Update();
	window->Show();

	Core::Render::IRenderSystemBase* renderSystem = nullptr;
	renderSystem = Core::Render::RegisterRenderSystem();
	renderSystem->Initialize("GapiOpenGL_Win32_Debug");
	renderSystem->CreateDevice(window->GetWindowDesc().handle);

	renderSystem->GetMaterialManager()->Load("../../../Assets/Xml/materials.xml");

	Scene::ISceneGraphBase* sceneGraph = nullptr;
	sceneGraph = Scene::RegisterSceneGraph();

	Scene::ISceneManagementBase* sceneManagement = nullptr;
	sceneManagement = Scene::RegisterSceneManagement();
	sceneManagement->ChangeState(PlayScene::GetInstancePtr(), renderSystem, sceneGraph);

	LARGE_INTEGER ticksPerSecond;
	LARGE_INTEGER currentTime;
	LARGE_INTEGER lastTime;
	UInt framesCount = 0; // Счетчик кадров.
	UInt framesPerSecond = 0; // Кадров в секунду.

	QueryPerformanceFrequency(&ticksPerSecond);
	QueryPerformanceCounter(&currentTime);
	QueryPerformanceCounter(&lastTime);

	System::ITimerBase* timer = nullptr;
	timer = System::RegisterTimer();
	timer->Start();

	while (window->MessageLoop(System::MESSAGE_LOOP_STATE::Run))
	{
		// Получаем интервал времени, которое прошло с момента последней отрисовки сцены.
		float timeStep = static_cast<float>(timer->GetInterval());

		sceneManagement->FrameStarted(window->GetInputManagement(), timeStep);

		renderSystem->GetDevice()->SetViewport(SCREEN_WIDTH, SCREEN_HEIGHT);
		renderSystem->FrameDrawed(sceneGraph->GetActiveCamera());

		sceneManagement->FrameEnded();

		// Увеличиваем счетчик кадров.
		framesCount++;

		// Если интервал времени между кадрами больше одной секунды.
		if (timeStep > 1000.0f)
		{
			timer->Stop(); // Останавливаем таймер.

			framesPerSecond = framesCount; // Сохраняем значение счетчика.
			framesCount = 0; // Обнуляем счетчик.

			// Запускаем таймер.
			timer->Start();
		}

		lastTime = currentTime;
	}

	SAFE_DELETE(sceneManagement);
	SAFE_DELETE(sceneGraph);
	SAFE_DELETE(renderSystem);
	SAFE_DELETE(window);

	return 0;
}