#include "ParticleSystem.h"

using namespace ParticleSystem;

class Sandbox : public App
{
public:
	
};

ParticleSystem::App * ParticleSystem::create()
{
	return new Sandbox;
}