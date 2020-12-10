#pragma once

#include "CompiledHeaders.h"
#include "Math/DynamicDatastructure.h"
#include "Type/Model.h"

namespace ParticleSystem
{
	class ModelCollection
	{
	public:
		SINGLETONIZE(ModelCollection)
		ModelCollection() {}

		void add(Model & model)
		{
			if (model.collection_index != 0)
				return;

			model.collection_index = models.get_size() + 1;
			models.push(model);
			names.push(model.model_name);
		};

		void remove(Model & model)
		{
			if (model.collection_index == 0)
				return;

			models.remove(model.collection_index - 1);
			names.remove(model.collection_index - 1);
			model.collection_index = 0;
		};

		bool exists(Model& model)
		{
			return model.collection_index != 0;
		}

		bool exists(std::string & name)
		{
			return names.has(name);
		}

		Model & get(unsigned int i) { return models.get_one(i); };

		virtual ~ModelCollection() = default;
	private:
		DynamicObject<Model> models;
		DynamicObject<std::string> names;
	};
}