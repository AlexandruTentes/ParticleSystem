#pragma once

#define INDEXBUFFER_H_

#include "../CompiledHeaders.h"
#include "../Type/Index.h"

namespace ParticleSystem
{
	class IndexBuffer : public DynamicObject<GLuint>
	{
	public:
		void load(Index const & data);
		void generate_buffers();
		void bind();
		void unbind() const;

		virtual ~IndexBuffer();
	private:
		DynamicObject<Index> cache;
	};
}