#include "../lib/GUI.h"

namespace ParticleSystem
{
	void GUI::attach()
	{
		handler = glfwGetWin32Window(window);
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplWin32_Init(handler);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void GUI::update()
	{
		ImGui_ImplOpenGL3_NewFrame();

		RECT rect;
		GetClientRect(handler, &rect);
		ImGui_ImplWin32_NewFrame(rect);

		ImGui::NewFrame();

		//Begin the GUI implementation
		ImGui::Begin(Global::get_instance().window_title);

		ImGui::SliderFloat("Scale", &temporary_globals::get_instance().scale, 0, 1);
		ImGui::SliderFloat("Rotation x", &temporary_globals::get_instance().rotation_x, 0, 360);
		ImGui::SliderFloat("Rotation y", &temporary_globals::get_instance().rotation_y, 0, 360);
		ImGui::SliderFloat("Rotation z", &temporary_globals::get_instance().rotation_z, 0, 360);
		ImGui::SliderFloat3("Position", temporary_globals::get_instance().translation, -1.0, 1.0);

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GUI::mouse_move_event(double x, double y)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(x, y);
	}

	void GUI::mouse_scroll_event(double x_offset, double y_offset)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += x_offset;
		io.MouseWheel += y_offset;
	}

	void GUI::mouse_click_event(int button, bool state)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[button] = state;
	}

	void GUI::text_event(unsigned int key)
	{
		ImGuiIO& io = ImGui::GetIO();
		if (key < 256) io.AddInputCharacter(key);
	}

	GUI::~GUI()
	{
		ImGui_ImplWin32_Shutdown();
		ImGui_ImplOpenGL3_DestroyDeviceObjects();
	}
}