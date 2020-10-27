#pragma once

#include "CompiledHeaders.h"

#ifdef WINDOWS

extern ParticleSystem::App * ParticleSystem::create();

int main()
{
	auto app = ParticleSystem::create();
	app->run();
	delete app;
}

#endif