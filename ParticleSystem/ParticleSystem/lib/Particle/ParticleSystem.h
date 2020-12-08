#pragma once

#include "../CompiledHeaders.h"
#include "ParticleCollection.h"
#include "../Math/UtilityFunctions.h"

namespace ParticleSystem
{
	class ParticleSystem
	{
	public:
		SINGLETONIZE(ParticleSystem)
		ParticleSystem() {};

		void emit(ParticleData & particle);
		void update(float const & time);
		void render();

		virtual ~ParticleSystem() = default;
	private:
		ParticleCollection& particles = ParticleCollection::get_instance();
		GLuint vertex_array;
		GLuint buffer_array;
		GLuint index_array;
	};
}