#pragma once

#include "../CompiledHeaders.h"
#include "ParticleCollection.h"
#include "../Math/UtilityFunctions.h"
#include "../Type/Model.h"
#include "../Renderer.h"

namespace ParticleSystem
{
	struct SystemData
	{
		SINGLETONIZE(SystemData)
		SystemData() {};
		ParticleData pd;
	};

	class ParticlePhysics
	{
	public:
		SINGLETONIZE(ParticlePhysics)
		ParticlePhysics() {};

		void emit(ParticleData & particle);
		void update(float const & time);
		void render(Renderer * r, Model & m);
		float fade_color(float color, float value, Particle & p);
		void move(float & p_coord, float value, float & velocity, Particle & p, bool snow = false);
		void GUI();
		void kill_all();
		void snow(ParticleData& pd);
		static void init_particle_data();

		virtual ~ParticlePhysics() = default;
	public:
		ParticleCollection& particles = ParticleCollection::get_instance();
		GLuint vertex_array;
		GLuint buffer_array;
		GLuint index_array;
		Model aux_model;
		SystemData& sd = SystemData::get_instance();
		float snow_time = 0.0f;
		float time_to_snow = 2.0f;
	};
}