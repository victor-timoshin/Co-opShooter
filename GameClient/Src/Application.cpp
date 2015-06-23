#include "../Inc/Application.h"

/** Constructor. */
Application::Application()
	: window(0L)
	, renderDevice(0L)
	, shader(0L)
	, vertexBuffer(0L)
	, indexBuffer(0L)
{
}

/** Destructor. */
Application::~Application()
{
}

void Application::CreateRenderSystem()
{
	Core::System::LWINDOWDESC windowDesc;
	windowDesc.proc = Core::System::ProcessEvent;
	windowDesc.mode = Core::System::WINDOWMODE::Windowed;
	windowDesc.title = "Demo";
	windowDesc.clientWidth = WINDOW_WIDTH;
	windowDesc.clientHeight = WINDOW_HEIGHT;

	window = Core::System::RegisterWindow(windowDesc);
	window->Create();
	window->Update();
	window->Show();

	renderDevice = Gapi::RegisterDevice(window);
	renderDevice->Initialize();
	renderDevice->SetViewport(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Application::CreateTriangle()
{
	shader = Gapi::RegisterShader(renderDevice);
	shader->CreateFromFile(
		"../../../Assets/Shaders/basic.vs",
		"../../../Assets/Shaders/basic.fs");

	vertexBuffer = Gapi::RegisterBuffer(renderDevice);
	vertexBuffer->Create(sizeof(Gapi::LVERTEXDIFFUSE_STRUCT), 4);

	Gapi::PVERTEXDIFFUSE_STRUCT vertices = static_cast<Gapi::PVERTEXDIFFUSE_STRUCT>(vertexBuffer->Lock());
	vertices[0].r = 0.0f;
	vertices[0].g = 255.0f;
	vertices[0].b = 255.0f;
	vertices[0].a = 255.0f;
	vertices[0].x = 0.0f;
	vertices[0].y = 0.1f;
	vertices[0].z = 0.5f;

	vertices[1].r = 255.0f;
	vertices[1].g = 0.0f;
	vertices[1].b = 255.0f;
	vertices[1].a = 255.0f;
	vertices[1].x = 0.5f;
	vertices[1].y = -0.5f;
	vertices[1].z = 0.5f;

	vertices[2].r = 255.0f;
	vertices[2].g = 255.0f;
	vertices[2].b = 0.0f;
	vertices[2].a = 255.0f;
	vertices[2].x = -0.5f;
	vertices[2].y = -0.5f;
	vertices[2].z = 0.0f;

	vertices[3].r = 0.0f;
	vertices[3].g = 255.0f;
	vertices[3].b = 255.0f;
	vertices[3].a = 255.0f;
	vertices[3].x = 0.5f;
	vertices[3].y = 0.5f;
	vertices[3].z = 0.0f;
	vertexBuffer->Unlock();

	indexBuffer = Gapi::RegisterBuffer(renderDevice);
	indexBuffer->Create(sizeof(UInt16), 6);

	UInt16* indices = static_cast<UInt16*>(indexBuffer->Lock());
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 1;
	indices[5] = 3;
	indexBuffer->Unlock();
}

void Application::Destroy()
{
	SAFE_DELETE(indexBuffer);
	SAFE_DELETE(vertexBuffer);
	SAFE_DELETE(shader);
	SAFE_DELETE(renderDevice);
	SAFE_DELETE(window);
}

void Application::Render()
{
	while (window->MainLoop(false))
	{
		renderDevice->Clear(0.0f, 0.0f, 0.0f, 0.0f);
		renderDevice->SetViewport(WINDOW_WIDTH, WINDOW_HEIGHT);

		shader->UseActiveObject();
		vertexBuffer->Render(Gapi::TYPE_TRIANGLELIST, indexBuffer, 0, 4, 0);

		renderDevice->Swap();
}
}

#ifdef PLATFORM_WINDOWS
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
#else
int main(int argc, char** argv)
#endif
{
	Application app;

	app.CreateRenderSystem();
	app.CreateTriangle();

	app.Render();

	app.Destroy();
	return 0;
}