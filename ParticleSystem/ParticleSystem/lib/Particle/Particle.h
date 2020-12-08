#pragma once

#include "../CompiledHeaders.h"

namespace ParticleSystem
{
	struct ParticleData
	{
		glm::vec4 position;
		glm::vec4 initial_color, variation_color, end_color;
		glm::vec4 velocity;
		glm::vec4 acceleration;
		float lifetime;
		float initial_size, end_size, variation_size;

		bool is_rotate = false;
		bool is_variation_size = false;
		bool is_variation_color = false;
		bool is_alive = false;
	};

	struct Particle
	{
		ParticleData data;

		float rotation = 0.0f;
		float life_remaining = 0.0f;
	};
}