#pragma once

#define APP_H_

#include "Platform.h"
#include "Display.h"
#include "GUI.h"
#include "Shader.h"
#include "Buffer/IndexBuffer.h"
#include "Buffer/VertexBuffer.h"
#include "Buffer/VertexBufferLayout.h"
#include "VertexArray.h"
#include "Type/Model.h"
#include "ModelParser/Parser.h"

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