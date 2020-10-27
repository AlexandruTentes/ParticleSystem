#pragma once

#define PLATFORM_H_

#include "CompiledHeaders.h"

#ifdef WINDOWS
	#ifdef BUILD_DLL
		#define API __declspec(dllexport)
	#else
		#define API __declspec(dllimport)
	#endif
#else
	#error Cannot operate on this paltform, Windows only!
#endif