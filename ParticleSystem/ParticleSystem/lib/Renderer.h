#pragma once

#include "CompiledHeaders.h"
#include "Type/Model.h"
#include "GlobalVariables.h"
#include "Math/Math.h"
#include "Shader.h"
#include "VertexArray.h"

namespace ParticleSystem
{
	class Renderer
	{
	public:
		Renderer() {};

		void render(Model & m);
		void draw(Model & m);

		virtual ~Renderer() = default;
	public:
		Matrix4d<float> view;
		Shader shader;
		VertexBuffer vb;
		IndexBuffer ib;
		VertexBufferLayout layout;
		VertexArray va;
	};
}