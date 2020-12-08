#pragma once

#define INDEX_H_

#include "../CompiledHeaders.h"
#include "../Math/DynamicDatastructure.h"
#include "../Math/Math.h"

namespace ParticleSystem
{
	class Index
	{
	public:
		bool has_fourth = false;
		DynamicObject<int> vertex;
		DynamicObject<int> texture;
		DynamicObject<int> normal;

		void add(Matrix4d<int> const & index);
	};
}