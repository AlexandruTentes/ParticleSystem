#pragma once

#include "../CompiledHeaders.h"
#include "../Type/Model.h"

namespace ParticleSystem
{
	struct ParticleData
	{
		ModelTransfData transform;
		float speed;
		float min_scale;
		float scale_speed;
		float min_color, max_color;
		float color_picker_min[3];
		float color_picker_max[3];
		float opacity_speed;
		float color_speed;
		float velocity_max;
		float snow_fall_speed;
		float snow_wiggle_speed;
		float snow_area_spawn[3];
		float velocity[3] =
		{
			0.0f, 0.0f, 0.0f
		};
		float velocity_variation[3] =
		{
			0.0f, 0.0f, 0.0f
		};
		float acceleration;
		float lifetime;
		float initial_size, end_size, variation_size;
		int particle_spawn;
		float ground_friction;

		bool tornado_mode = false;
		bool is_rotate = false;
		bool is_variation_size = false;
		bool is_variation_color = false;
		bool is_alive = false;
		bool is_on_ground = false;
		bool color_fade = false;
		bool repeat_mode = false;
	};

	struct Particle
	{
		ParticleData data;
		float rotation = 0.0f;
		float life_remaining = 0.0f;
		bool has_model = false;
	};
}