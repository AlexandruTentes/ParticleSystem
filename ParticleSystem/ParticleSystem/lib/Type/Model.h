#pragma once

#define MODEL_H_

#include "Index.h"
#include "Vertex.h"
#include "Normal.h"
#include "Texture.h"

///////////////////////////////////////
//===== The mdoel datastructure =====//
///////////////////////////////////////

namespace ParticleSystem
{
	class Model
	{
	public:
		Model();
		Model(Vertex & vertex, Normal & normal, Texture & texture, Index & index);
		void set(Vertex & vertex, Normal & normal, Texture & texture, Index & index);
		void set(Model & model);

		~Model();
	public:
		Vertex vertex;
		Normal normal;
		Texture texture;
		Index index;
	};
}