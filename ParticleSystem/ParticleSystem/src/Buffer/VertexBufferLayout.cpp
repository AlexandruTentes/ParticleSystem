#include "../../lib/Buffer/VertexBufferLayout.h"

namespace ParticleSystem
{
	void VertexBufferLayout::load(GLuint type, GLuint size)
	{
		push(_VertexBufferLayout{ type, size, (type == GL_UNSIGNED_BYTE ? true : false) });
		this->stride += size * get_sizeof_gltype(type);
	}

	GLuint VertexBufferLayout::get_stride() const
	{
		return stride;
	}
}