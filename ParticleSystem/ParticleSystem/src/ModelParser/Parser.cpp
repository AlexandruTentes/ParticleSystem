#include "../../../lib/ModelParser/Parser.h"

namespace ParticleSystem
{
	void read_raw_model(FileAndPath & file)
	{
		switch (file.extension_index)
		{
		case OBJ: 
		{ 
			OBJParser obj;
			obj.read_extension(file.path + "\\" + file.file, file.file);
		}
		}
	}
}