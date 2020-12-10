#pragma once

#include "CompiledHeaders.h"
#include "Math/DynamicDatastructure.h"

namespace ParticleSystem
{
	class FolderData
	{
	public:
		SINGLETONIZE(FolderData)
		FolderData() {};

		virtual ~FolderData() = default;
	public:
		DynamicObject<FileAndPath> files;
	};
}