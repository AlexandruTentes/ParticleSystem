#pragma once

#define APP_H_

#include "Platform.h"
#include "Display.h"
#include "GUI.h"

namespace ParticleSystem
{
	class API App
	{
	public:
		void run();
		virtual ~App() = default;
	private:
		Display& display = Display::get_instance();
		GUI& gui = GUI::get_instance();
	};

	App * create();
}