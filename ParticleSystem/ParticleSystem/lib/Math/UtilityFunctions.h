#pragma once

#define UTILITYFUNCTIONS_H_

#include "../CompiledHeaders.h"
#include "DynamicDatastructure.h"
#include "Strmanip.h"

namespace ParticleSystem
{
	void get_files_directory(DynamicObject<FileAndPath> & files, std::string & path, std::string * extension, int const & size = 0);
	int get_sizeof_gltype(unsigned int type);
	float random(unsigned int a, unsigned int b);
}