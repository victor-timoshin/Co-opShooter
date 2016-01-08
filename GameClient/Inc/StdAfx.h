#ifndef STDAFX_H
#define STDAFX_H

#include "Core/Utils/LoggerBase.h"
#include "System/WindowBase.h"
#include "System/TimerBase.h"
#include "OIS/InputBase.h"

#include "Gapi/DeviceBase.h"
#include "Gapi/ShaderBase.h"
#include "Gapi/BufferBase.h"
#include "Gapi/Types.h"

#include "Core/Render/RenderSystemBase.h"

#include "Core/Scene/SceneStateBase.h"
#include "Core/Scene/SceneManagementBase.h"
#include "SceneGraph/SceneGraphBase.h"
#include "SceneGraph/SceneNodeBase.h"

#include "GUI/FontBase.h"

#include "Platform.h"

#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib, "System_Win32_Debug")
#pragma comment(lib, "GapiOpenGL_Win32_Debug")
#pragma comment(lib, "Core_Win32_Debug")
#pragma comment(lib, "OIS_Win32_Debug")
#pragma comment(lib, "SceneGraph_Win32_Debug")
#pragma comment(lib, "GUI_Win32_Debug")
#endif

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#endif // STDAFX_H