#ifndef STDAFX_H
#define STDAFX_H

#include "Core/Utils/LogBase.h"
#include "Core/System/WindowBase.h"
#include "Core/Math/Vertex.h"

#include "Gapi/DeviceBase.h"
#include "Gapi/ShaderBase.h"
#include "Gapi/BufferBase.h"
#include "Gapi/Types.h"

#include "Core/Render/RenderSystemBase.h"

#include "Core/Scene/SceneStateBase.h"
#include "Core/Scene/SceneManagementBase.h"
#include "Core/Scene/SceneGraphBase.h"
#include "Core/Scene/SceneNodeBase.h"

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

#endif // STDAFX_H