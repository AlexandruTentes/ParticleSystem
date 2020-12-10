#include "../lib/GUI.h"

namespace ParticleSystem
{
	static ImVec4 color = ImVec4(114.0f / 255.0f, 144.0f / 255.0f, 154.0f / 255.0f, 200.0f / 255.0f);

	void GUI::attach()
	{
		handler = glfwGetWin32Window(window);
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplWin32_Init(handler);
		ImGui_ImplOpenGL3_Init("#version 410");

		if (model != nullptr)
			return;

		model = new Renderer();
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

		bool open_popup = false;
		for (unsigned int i = 0; i < folder.files.get_size(); i++)
		{
			open_popup |= ImGui::Button(folder.files.get_one(i).file.c_str());
			if (open_popup)
			{
				read_raw_model(folder.files.get_one(i));
				model->render(models.get(i));
				ImGui::OpenPopup((folder.files.get_one(i).file + " Transformation Matrix").c_str());
			}
			if (ImGui::BeginPopup((folder.files.get_one(i).file + " Transformation Matrix").c_str()))
			{
				ImGui::Text(folder.files.get_one(i).file.c_str());
				model->draw(models.get(i));
				models.get(i).GUI();

				ImGui::EndPopup();
			}
		}

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
		delete model;
	}
}