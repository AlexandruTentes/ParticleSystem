#include "../../lib/Type/Vertex.h"

namespace ParticleSystem
{
	void Vertex::add(Vector3d<float> vertex)
	{
		push(vertex);
	}
}