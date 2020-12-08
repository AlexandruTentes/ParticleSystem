#include "../../lib/Particle/ParticleSystem.h"

namespace ParticleSystem
{
	void ParticleSystem::emit(ParticleData & particle_data)
	{
		Particle& particle = particles.particle_array[particles.current_index];

		particle.data = particle_data;
		particle.rotation = random(0, 2) * glm::pi<float>();
		particle.data.velocity.x += particle_data.velocity.x * (random(0, 5) / 10);
		particle.data.velocity.y += particle_data.velocity.y * (random(0, 5) / 10);
		particle.data.initial_size = particle_data.initial_size + particle_data.variation_size * (random(0, 5) / 10);

		particles.current_index = (particles.current_index - 1) % particles.capacity;
	}

	void ParticleSystem::update(float const & time)
	{
		for (unsigned int i = 0; i < particles.particle_array.size(); i++)
		{
			if (particles.particle_array[i].data.is_alive)
			{
				if (particles.particle_array[i].life_remaining > 0.0f)
				{
					particles.particle_array[i].life_remaining -= time;
					particles.particle_array[i].data.position += particles.particle_array[i].data.velocity * time;
					particles.particle_array[i].rotation += 0.01f * time; 
				}
				else particles.particle_array[i].data.is_alive = false;
			}
		}
	}

	void ParticleSystem::render()
	{

	}
}