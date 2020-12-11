#pragma once

#include "../CompiledHeaders.h"
#include "Particle.h"

namespace ParticleSystem
{
	class ParticleCollection
	{
	public:
		SINGLETONIZE(ParticleCollection)
		ParticleCollection();
		virtual ~ParticleCollection() = default;
	public:
		unsigned int capacity = 100000;
		unsigned int current_index = capacity - 1;

		std::vector<Particle> particle_array;
		unsigned int alive_no = 0;
		unsigned int no = 0;
	};
}