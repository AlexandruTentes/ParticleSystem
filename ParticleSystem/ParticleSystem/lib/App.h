#pragma once

#define APP_H_

#include "Platform.h"

namespace ParticleSystem
{
	class API App
	{
	public:
		void run();

		virtual ~App() = default;
	};

	App * create();
}