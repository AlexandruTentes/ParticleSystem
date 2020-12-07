#pragma once

#include "CompiledHeaders.h"
#include "GUI.h"
#include "Events.h"
#include "GlobalVariables.h"

namespace ParticleSystem
{
	class Display
	{
	public:
		GLFWwindow* window = nullptr;
	public:
		SINGLETONIZE(Display)
		Display();
		bool running();
		void vsync(bool const & flag);
		virtual ~Display();
	private:
		GUI& gui = GUI::get_instance();
		Global & global = Global::get_instance();
	};
}