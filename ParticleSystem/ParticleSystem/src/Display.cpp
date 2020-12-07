#include "../lib/Display.h"

namespace ParticleSystem
{
	Display::Display()
	{
		glfwSetErrorCallback(glfw_error_callback);

		if (!glfwInit())
			FATAL_ERROR("Failed to initialize glfw window!");

		if (!(window = glfwCreateWindow(global.window_width, global.window_height,
			global.window_title, NULL, NULL)))
			FATAL_ERROR("Window/OpenGL context creation failed!");

		gui.window = window;
		glfwMakeContextCurrent(window);

		glfwSetCharCallback(window, glfw_char_callback);
		glfwSetScrollCallback(window, glfw_scroll_callback);
		glfwSetCursorPosCallback(window, glfw_mouse_callback);
		glfwSetMouseButtonCallback(window, glfw_mouse_btn_callback);
		glfwSetKeyCallback(window, glfw_key_callback);

		vsync(true);

		glewInit();
		gui.attach();
	}
	bool Display::running()
	{
		return !glfwWindowShouldClose(window);
	}
	void Display::vsync(bool const & flag)
	{
		glfwSwapInterval(flag);
	}
	Display::~Display()
	{
		glfwTerminate();
	}
}