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
		ImGui::Begin("Rainbow Snow Flakes System");

		bool open_popup = false;
		for (unsigned int i = 0; i < folder.files.get_size(); i++)
		{
			open_popup |= ImGui::Button("Rainbow Snow Flakes System");
			if (open_popup)
			{
				read_raw_model(folder.files.get_one(i));
				model->render(models.get(i));
				particle.kill_all();
				ImGui::OpenPopup("Rainbow Snow Flakes System");
			}
			if (ImGui::BeginPopup("Rainbow Snow Flakes System"))
			{
				ImGui::Text("Rainbow Snow Flakes System");
				ParticlePhysics p;
				p.render(model, models.get(i));
				//models.get(i).GUI();
				particle.GUI();

				if (sd.pd.repeat_mode && particle.particles.alive_no == 0)
					for (unsigned int i = 0; i < sd.pd.particle_spawn; i++)
						particle.emit(sd.pd);
				else if (!sd.pd.repeat_mode)
					particle.snow(sd.pd);	

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