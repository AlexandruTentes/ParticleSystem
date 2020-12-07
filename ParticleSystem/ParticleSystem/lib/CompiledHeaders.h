#pragma once

#include <iostream>
#include <string>
#include <windows.h>

#include "Macro.h"

#ifdef _WIN64
	#define WINDOWS
#endif

#ifdef BUILD_DLL
	#include <GL/glew.h>
	#include <GL/freeglut.h>
	#include <GLFW/glfw3.h>
	#define GLFW_EXPOSE_NATIVE_WGL
	#define GLFW_EXPOSE_NATIVE_WIN32 
	#include <GLFW/glfw3native.h>
#endif