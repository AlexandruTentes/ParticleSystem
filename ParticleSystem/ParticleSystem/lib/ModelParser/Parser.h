#pragma once

#define PARSER_H_

#include "../CompiledHeaders.h"
#include "../Math/UtilityFunctions.h"
#include "../Math/Math.h"
#include "../GlobalVariables.h"
#include "OBJParser.h"
#include "../ModelCollection.h"
#include "../FolderData.h"

namespace ParticleSystem
{
	void read_raw_model(FileAndPath& file);
}