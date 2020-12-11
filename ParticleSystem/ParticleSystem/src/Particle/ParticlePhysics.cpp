#include "../../lib/Particle/ParticlePhysics.h"

namespace ParticleSystem
{
	void ParticlePhysics::emit(ParticleData & particle_data)
	{
		Particle& particle = particles.particle_array[particles.current_index];

		particle.data = particle_data;
		particle.rotation = random(0, 2) * glm::pi<float>();
		particle.data.velocity[0] += random(0, particle.data.velocity_max) / particle.data.snow_wiggle_speed - 
			particle.data.velocity_max / (2 * particle.data.snow_wiggle_speed);
		particle.data.velocity[1] += -random(0, particle.data.velocity_max);
		particle.data.velocity[2] += random(0, particle.data.velocity_max) / particle.data.snow_wiggle_speed -
			particle.data.velocity_max / (2 * particle.data.snow_wiggle_speed);
		particle.data.initial_size = particle_data.initial_size + particle_data.variation_size * (random(0, 5) / 10);
		particle.data.is_alive = true;
		particles.alive_no++;
		particles.no++;
		particle.life_remaining = particle_data.lifetime;
		particle.data.transform.color[0] = random(particle.data.color_picker_min[0] - 1, particle.data.color_picker_max[0]);
		particle.data.transform.color[1] = random(particle.data.color_picker_min[1] - 1, particle.data.color_picker_max[1]);
		particle.data.transform.color[2] = random(particle.data.color_picker_min[2] - 1, particle.data.color_picker_max[2]);
		particle.data.transform.translation[0] = random(0, particle.data.snow_area_spawn[0]) - particle.data.snow_area_spawn[0] / 2;
		particle.data.transform.translation[1] = particle.data.repeat_mode ? random(0, particle.data.snow_area_spawn[1]) : 0.95 / particle.data.snow_area_spawn[1];
		particle.data.transform.translation[2] = random(0, particle.data.snow_area_spawn[2]) - particle.data.snow_area_spawn[2] / 2;

		particles.current_index = (particles.current_index - 1) % particles.capacity;
	}

	void ParticlePhysics::update(float const & time)
	{
		for (unsigned int i = 0; i < particles.particle_array.size(); i++)
		{
			Particle& p = particles.particle_array[i];
			if (p.data.is_alive)
			{
				if (p.life_remaining > 0.0f)
				{
					if(p.data.repeat_mode)
						p.life_remaining -= time;
					else if(!p.data.repeat_mode && p.data.is_on_ground)
						p.life_remaining -= time;
					
					p.data.transform.color[0] = fade_color(p.data.transform.color[0], time * p.data.color_speed, p);
					p.data.transform.color[1] = fade_color(p.data.transform.color[1], time * p.data.color_speed, p);
					p.data.transform.color[2] = fade_color(p.data.transform.color[2], time * p.data.color_speed, p);

					if (p.data.is_on_ground)
					{
						p.data.transform.scale -= p.data.is_variation_size ? (time * p.data.scale_speed) : 0;
						p.data.transform.scale = p.data.transform.scale < p.data.min_scale ? p.data.min_scale : p.data.transform.scale;
					}

					if (p.data.is_on_ground)
					{
						p.data.transform.opacity -= time * p.data.opacity_speed;
						p.data.velocity[0] /= p.data.ground_friction;
						p.data.velocity[2] /= p.data.ground_friction;
					}

					if (!p.data.is_on_ground)
					{
						p.data.transform.rotation[0] += (random(0, 1) > 5 ? 1 : -1) * p.data.rotation_speed;
						p.data.transform.rotation[1] += (random(0, 1) > 5 ? 1 : -1) * p.data.rotation_speed;
						p.data.transform.rotation[2] += (random(0, 1) > 5 ? 1 : -1) * p.data.rotation_speed;
					}
					
					if(p.data.tornado_mode)
						p.data.velocity[0] += ((random(0, 1) > 5 ? 1 : -1) * random(0, 1) / 10) * p.data.snow_wiggle_speed;

					if (wiggle_time > time_to_wiggle)
					{
						wiggle_value = (random(0, 1) > 5 ? 1 : -1) * wiggle_value;
						wiggle_time = 0.0f;
					}

					p.data.velocity[0] *= wiggle_value;
					p.data.velocity[1] = -p.data.snow_fall_speed;
					p.data.velocity[2] *= wiggle_value;
					move(p.data.transform.translation[0], time * p.data.speed, p.data.velocity[0], p);
					move(p.data.transform.translation[1], time * p.data.speed, p.data.velocity[1], p, true);
					move(p.data.transform.translation[2], time * p.data.speed, p.data.velocity[2], p);

					if(!p.data.tornado_mode)
						wiggle_time += 0.001f;
				}
				else
				{
					particles.alive_no--;
					p.data.is_on_ground = false;
					particles.particle_array[i].data.is_alive = false;
				}
			}
		}
	}

	void ParticlePhysics::render(Renderer * r, Model & m)
	{
		float health;
		Particle p;
		glm::vec4 color;

		for (unsigned int i = 0; i < particles.capacity; i++)
		{
			if (particles.particle_array[i].data.is_alive)
			{
				p = particles.particle_array[i];
				aux_model.set(m);
				
				aux_model.data.scale = p.data.transform.scale <= p.data.min_scale ? p.data.min_scale : p.data.transform.scale;
				aux_model.data.color[0] = p.data.transform.color[0];
				aux_model.data.color[1] = p.data.transform.color[1];
				aux_model.data.color[2] = p.data.transform.color[2];
				aux_model.data.opacity = p.data.transform.opacity;
				aux_model.data.rotation[0] = p.data.transform.rotation[0];
				aux_model.data.rotation[1] = p.data.transform.rotation[1];
				aux_model.data.rotation[2] = p.data.transform.rotation[2];
				aux_model.data.translation[0] = p.data.transform.translation[0];
				aux_model.data.translation[1] = p.data.transform.translation[1];
				aux_model.data.translation[2] = p.data.transform.translation[2];
				
				aux_model.rendered = true;

				r->view.set(sd.camera[0], sd.camera[1], sd.camera[2], 0,
					0, 0, sd.camera_coord[0], 0,
					0, sd.camera_coord[1], 0, 0,
					0, 0, 0, 0);

				r->draw(aux_model);
			}
		}

		update(0.005);
	}

	float ParticlePhysics::fade_color(float color, float value, Particle & p)
	{
		float result = p.data.min_color;
		result = color + (!p.data.color_fade ? value : -1 * value);

		if (result >= p.data.max_color)
			p.data.color_fade = true;
		else if (result <= p.data.min_scale)
			p.data.color_fade = false;

		return result;
	}

	void ParticlePhysics::move(float& p_coord, float value, float & velocity,  Particle& p, bool snow)
	{
		float result = 0.0f;
		float size_diff = 1.0 - p.data.transform.scale;

		if ((p_coord < -0.95 - size_diff || p_coord > 0.95 + size_diff) && !snow)
			velocity *= -1;
		else if (p_coord < -0.95 && snow)
		{
			velocity = 0;
			p.data.is_on_ground = true;
		}

		result += value * velocity;
		p_coord += result * p.data.acceleration;
	}

	void ParticlePhysics::GUI()
	{
		bool btn;
		double current_time = glfwGetTime();
		frames++;

		//Begin the GUI implementation
		ImGui::SliderFloat("Color Speed", &sd.pd.color_speed, 0, 500);
		ImGui::SliderFloat("Scale Speed", &sd.pd.scale_speed, 0, 5);
		ImGui::SliderFloat("Opacity Speed", &sd.pd.opacity_speed, 0, 1);
		ImGui::SliderFloat("Acceleration", &sd.pd.acceleration, 0, 1);
		ImGui::SliderFloat("Lifetime", &sd.pd.lifetime, 0, 50);
		ImGui::SliderFloat("Speed", &sd.pd.speed, 0, 500);
		ImGui::SliderFloat("Rotation Speed", &sd.pd.rotation_speed, 0, 10);
		ImGui::SliderFloat("Scale", &sd.pd.transform.scale, 0, 1);
		ImGui::SliderFloat("Min Scale", &sd.pd.min_scale, 0, 1);
		ImGui::SliderFloat("Min Color", &sd.pd.min_color, 10, 100);
		ImGui::SliderFloat("Max Color", &sd.pd.max_color, 180, 230);
		ImGui::SliderFloat3("Color Picker Min", sd.pd.color_picker_min, 1, 255);
		ImGui::SliderFloat3("Color Picker Max", sd.pd.color_picker_max, 1, 255);
		ImGui::SliderFloat("Max Velocity", &sd.pd.velocity_max, 1, 3);
		ImGui::SliderFloat("Snow Fall", &sd.pd.snow_fall_speed, 0, 1);
		ImGui::SliderFloat("Snow Wiggle", &sd.pd.snow_wiggle_speed, 10, 1);
		ImGui::SliderFloat3("Snow area spawn", sd.pd.snow_area_spawn, -10, 10);
		ImGui::SliderFloat("Ground Friction", &sd.pd.ground_friction, 1, 2);
		ImGui::SliderFloat3("Camera", sd.camera, -10, 10);
		ImGui::SliderFloat2("Camera Coord", sd.camera_coord, -1, 1);
		ImGui::SliderInt("Particle Spawn", &sd.pd.particle_spawn, 0, 5000);

		if (ImGui::Button("Reset Particle Data"))
			init_particle_data();

		ImGui::SameLine();
		ImGui::TextColored(ImVec4(1, 1, 0, 1), ("FPS: " + fps).c_str());
		ImGui::SameLine();
		ImGui::Text(("Particles: " + std::to_string(particles.alive_no)).c_str());

		if (current_time - prev_time >= 1.0)
		{
			fps = std::to_string(frames);
			frames = 0;
			prev_time += current_time;
		}

		ImGui::NewLine();

		btn = ImGui::Button("Repeat Mode: ");
			
		if (btn && !sd.pd.repeat_mode)
		{
			sd.pd.tornado_mode = false;
			sd.pd.repeat_mode = true;
		}
		else if (btn && sd.pd.repeat_mode)
		{
			sd.pd.tornado_mode = false;
			sd.pd.repeat_mode = false;
		}

		ImGui::SameLine();
		ImGui::Text(sd.pd.repeat_mode ? " ON" : " OFF");
		ImGui::SameLine();
		btn = ImGui::Button("Tornado Mode: ");

		if(!sd.pd.repeat_mode)
			if (btn && !sd.pd.repeat_mode)
			{
				sd.pd.repeat_mode = false;
				sd.pd.tornado_mode = true;
			}
			else if (btn && sd.pd.repeat_mode)
			{
				sd.pd.repeat_mode = false;
				sd.pd.tornado_mode = false;
			}

		ImGui::SameLine();
		ImGui::Text(sd.pd.tornado_mode ? " ON" : " OFF");
	}

	void ParticlePhysics::kill_all()
	{
		for (unsigned int i = 0; i < particles.capacity; i++)
			if (particles.particle_array[i].data.is_alive)
			{
				particles.particle_array[i].data.is_alive = false;
				particles.alive_no--;
			}

		particles.alive_no = 0;
	}

	void ParticlePhysics::snow(ParticleData& pd)
	{
		snow_time += 0.0001f;

		if (snow_time = time_to_snow)
		{
			for(unsigned int i = 0; i < sd.pd.particle_spawn; i++)
				emit(pd);

			snow_time = 0.0f;
		}
	}

	void ParticlePhysics::init_particle_data()
	{
		ParticleData pd;
		pd.transform.scale = 0.005f;
		pd.color_speed = 200.0f;
		pd.scale_speed = 0.5f;
		pd.min_scale = 0.005;
		pd.initial_size = 1.0f;
		pd.variation_size = 3.0f;
		pd.acceleration = 0.06f;
		pd.lifetime = 2.0f;
		pd.min_color = 20;
		pd.max_color = 220;
		pd.speed = 35.0f;
		pd.opacity_speed = 0.6f;
		pd.velocity_max = 3.0f;
		pd.particle_spawn = 10;
		pd.snow_fall_speed = 0.5;
		pd.snow_wiggle_speed = 10;
		pd.snow_area_spawn[0] = 2;
		pd.snow_area_spawn[1] = 1;
		pd.snow_area_spawn[2] = 2;
		pd.ground_friction = 1.1;
		pd.repeat_mode = false;
		pd.tornado_mode = false;
		pd.color_picker_min[0] = 32;
		pd.color_picker_min[1] = 195;
		pd.color_picker_min[2] = 208;
		pd.color_picker_max[0] = 63;
		pd.color_picker_max[1] = 208;
		pd.color_picker_max[2] = 212;
		pd.rotation_speed = 1.0f;
		pd.is_variation_size = false;

		SystemData& sd = SystemData::get_instance();
		sd.pd = pd;
		sd.camera[0] = 0;
		sd.camera[1] = 0;
		sd.camera[2] = -3;
		sd.camera_coord[0] = 1;
		sd.camera_coord[1] = 1;
	}
}