#include "../../../lib/ModelParser/Parser.h"

namespace ParticleSystem
{
	void read_raw_model(Model & model)
	{
		DynamicObject<FileAndPath> files;
		get_files_directory(files, std::string(Global::get_instance().model_path), model_extension, sizeof(model_extension) / sizeof(model_extension[0]));

		for (int i = 0; i < files.get_size(); i++)
		{
			switch (files.get_one(i).extension_index)
			{
			case OBJ: { OBJParser obj; obj.read_extension(files.get_one(i).path + "\\" + files.get_one(i).file); model.set(obj.model); }
			}
		}
	}
}