#pragma once

#define PARSER_H_

#include "../CompiledHeaders.h"
#include "../Type/Model.h"
#include "../Math/UtilityFunctions.h"
#include "../Math/Math.h"
#include "../GlobalVariables.h"
#include "OBJParser.h"

namespace ParticleSystem
{
	static std::string model_extension[] =
	{
		".obj"
	};

	//===== Model file extension =====//
	enum ModelExtension
	{
		OBJ
	};

	void read_raw_model(Model & model);
}