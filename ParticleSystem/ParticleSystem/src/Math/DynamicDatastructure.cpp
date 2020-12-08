#include "../../lib/Math/DynamicDatastructure.h"

///////////////////////////////////////////////////
//===== The filename and path datastructure =====//
///////////////////////////////////////////////////

namespace ParticleSystem
{
	FileAndPath::FileAndPath()
	{}

	FileAndPath::FileAndPath(std::string const& file, unsigned int const& extension_index, std::string const& path)
	{
		add(file, extension_index, path);
	}
	void FileAndPath::add(std::string const & file, unsigned int const& extension_index, std::string const & path)
	{
		this->file = file;
		this->path = path;
		this->extension_index = extension_index;
	}
}