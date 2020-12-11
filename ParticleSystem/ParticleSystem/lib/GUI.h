#pragma once

#include "CompiledHeaders.h"
#include "GlobalVariables.h"
#include "FolderData.h"
#include "thirdparty/imgui/imgui.h"
#include "thirdparty/imgui/imgui_impl_win32.h"
#include "thirdparty/imgui/imgui_impl_opengl3.h"
#include "ModelCollection.h"
#include "ModelParser/Parser.h"
#include "Particle/ParticlePhysics.h"
#include "Renderer.h"

namespace ParticleSystem
{
	struct temporary_globals
	{
		SINGLETONIZE(temporary_globals)
		temporary_globals() {};

		float scale = 1.0f;
		float rotation[3] = {0.0f, 0.0f, 0.0f};
		float translation[3] = { 0.0f, 0.0f, 0.0f };
		float color[3] = {255.0f, 0.0f, 0.0f};
		float opacity = 1.0f;
	};

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
		FolderData& folder = FolderData::get_instance();
		ModelCollection& models = ModelCollection::get_instance();
		Renderer * model = nullptr;
		ParticlePhysics particle;
		SystemData& sd = SystemData::get_instance();
	};
}