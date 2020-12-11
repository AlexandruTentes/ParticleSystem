#pragma once

#include "CompiledHeaders.h"
#include "GUI.h"

namespace ParticleSystem
{
	static void glfw_error_callback(int error, const char* description)
	{
		std::cout << "ERROR: " << description << "\n";
	}

	static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	static void glfw_mouse_btn_callback(GLFWwindow* window, int button, int action, int mods)
	{
		GUI::get_instance().mouse_click_event(button, action);
	}

	static void glfw_scroll_callback(GLFWwindow* window, double x, double y)
	{
		GUI::get_instance().mouse_scroll_event(x, y);
	}

	static void glfw_mouse_callback(GLFWwindow* window, double x, double y)
	{
		GUI::get_instance().mouse_move_event(x, y);
	}

	static void glfw_char_callback(GLFWwindow* window, unsigned int codepoint)
	{
		GUI::get_instance().text_event(codepoint);
	}

	static void glfw_resize_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}