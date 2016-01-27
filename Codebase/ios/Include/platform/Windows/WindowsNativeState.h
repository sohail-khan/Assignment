// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "EegeoWindowsGuard.h"
#include <EGL\egl.h>
#include <EGL\eglplatform.h>

struct WindowsNativeState
{
	HINSTANCE	hinstance;
	const char*		appName;
	bool		fullScreen;

	int			screenWidth;
	int			screenHeight;

	EGLNativeWindowType	window;
	bool		requiresPBuffer;

	std::string		deviceModel;
	
	float		deviceDpi;
};