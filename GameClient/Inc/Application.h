#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core/System/WindowBase.h"
#include "Gapi/DeviceBase.h"

#include "Gapi/ShaderBase.h"
#include "Gapi/BufferBase.h"
#include "Gapi/Vertex.h"
#include "Gapi/Types.h"

#include "Platform.h"

#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib, "GapiOpenGL_Win32_Debug")
#pragma comment(lib, "Core_Win32_Debug")
#else
#pragma comment(lib, "GapiOpenGL_Win32_Release")
#pragma comment(lib, "Core_Win32_Release")
#endif

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Application
{
public:
	/** Constructor. */
	Application();

	/** Destructor. */
	~Application();

	void CreateRenderSystem();
	void CreateTriangle();

	void Render();

	void Destroy();

private:
	Core::System::IWindowBase* window;
	Gapi::IDeviceBase* renderDevice;
	Gapi::IShaderBase* shader;
	Gapi::IBufferBase* vertexBuffer;
	Gapi::IBufferBase* indexBuffer;
};

#endif