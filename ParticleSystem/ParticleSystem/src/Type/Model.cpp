#include "../../lib/Type/Model.h"

namespace ParticleSystem
{
	Model::Model()
	{}

	Model::Model(Vertex & vertex, Normal & normal, Texture & texture, Index & index, std::string const& model_name)
	{
		set(vertex, normal, texture, index, model_name);
	}

	void Model::set(Vertex & vertex, Normal & normal, Texture & texture, Index & index, std::string const & model_name)
	{
		this->vertex = std::move(vertex);
		this->normal = std::move(normal);
		this->texture = std::move(texture);
		this->index = std::move(index);
		this->model_name = model_name;
	}

	void Model::set(Model& model)
	{
		set(model.vertex, model.normal, model.texture, model.index, model.model_name);
	}

	void Model::animate()
	{
		float sinc = sinf(degree);
		float cosc = cosf(degree);
		data.translation[0] = sinc;
		data.translation[2] = cosc;
		data.rotation[0] = degree * 50;
		data.rotation[1] = degree * 50;
		data.rotation[2] = degree * 50;

		degree += 0.01f;
	}

	void Model::GUI()
	{
		//Begin the GUI implementation
		ImGui::SliderFloat("Scale", &data.scale, 0, 1);
		ImGui::SliderFloat3("Position", data.translation, -1.0, 1.0);
		ImGui::SliderFloat3("Rotation", data.rotation, 0, 359);
		ImGui::SliderFloat3("Color", data.color, 0, 255);
		ImGui::SliderFloat("Opacity", &data.opacity, 0, 1);

		bool btn = ImGui::Button("Animation: ");

		if (btn && !animation)
			animation = true;
		else if (btn && animation)
			animation = false;

		ImGui::SameLine();
		ImGui::Text(animation ? " ON" : " OFF");

		if (animation)
			animate();
	}
}
