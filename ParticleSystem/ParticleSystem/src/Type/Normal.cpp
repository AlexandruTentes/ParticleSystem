#include "../../lib/Type/Normal.h"

namespace ParticleSystem
{
	void Normal::add(Vector3d<float> normal)
	{
		push(normal);
	}
}