#include "../../lib/Type/Model.h"

namespace ParticleSystem
{
	Model::Model()
	{}

	Model::Model(Vertex & vertex, Normal & normal, Texture & texture, Index & index) 
	{
		set(vertex, normal, texture, index);
	}

	void Model::set(Vertex & vertex, Normal & normal, Texture & texture, Index & index)
	{
		this->vertex = std::move(vertex);
		this->normal = std::move(normal);
		this->texture = std::move(texture);
		this->index = std::move(index);
	}

	void Model::set(Model& model)
	{
		set(model.vertex, model.normal, model.texture, model.index);
	}

	Model::~Model()
	{}
}
