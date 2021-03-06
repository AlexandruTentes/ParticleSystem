#include "../../lib/Type/Index.h"

namespace ParticleSystem
{
	void Index::add(Matrix4d<int> const & index)
	{
		vertex.push(index.mat[0][0] - 1);
		vertex.push(index.mat[1 + has_fourth][0] - 1);
		vertex.push(index.mat[2 + has_fourth][0] - 1);

		texture.push(index.mat[0][1]);
		texture.push(index.mat[1 + has_fourth][1]);
		texture.push(index.mat[2 + has_fourth][1]);

		normal.push(index.mat[0][2]);
		normal.push(index.mat[1 + has_fourth][2]);
		normal.push(index.mat[2 + has_fourth][2]);
	}
}