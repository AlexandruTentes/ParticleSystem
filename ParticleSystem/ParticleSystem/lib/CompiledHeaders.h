#pragma once

#include <iostream>
#include <string>

#ifdef _WIN64
	#define WINDOWS
#endif

#ifdef BUILD_DLL
	#include <GL/glew.h>
	#include <GL/freeglut.h>
#endif