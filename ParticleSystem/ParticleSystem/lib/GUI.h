#pragma once

#include "CompiledHeaders.h"
#include "GlobalVariables.h"

#include "thirdparty/imgui/imgui.h"
#include "thirdparty/imgui/imgui_impl_win32.h"
#include "thirdparty/imgui/imgui_impl_opengl3.h"

namespace ParticleSystem
{
	class GUI
	{
	public:
		SINGLETONIZE(GUI)

		GUI() {}
		void attach();
		void update();
		void mouse_move_event(double x, double y);
		void mouse_scroll_event(double x_offset, double y_offset);
		void mouse_click_event(int button, bool state);
		void text_event(unsigned int key);

		virtual ~GUI();
	public:
		Global& global = Global::get_instance();
		GLFWwindow* window = nullptr;
		HWND handler = NULL;
	private:
		float prev_time = 0.0f;
	};
}