#include "../../lib/Math/UtilityFunctions.h"

namespace ParticleSystem
{
	void get_files_directory(DynamicObject<FileAndPath>& files, std::string & path, std::string * extension, int const & size)
	{
		std::string original_path = path;
		path += "\\";
		int i = 0;
		int j = 0;
		bool add_data = true;

		WIN32_FIND_DATA file;
		HANDLE file_handler;

		try
		{
			if ((file_handler = FindFirstFile((path + "*").c_str(), & file)) != INVALID_HANDLE_VALUE)
			{
				while (true)
				{
					if (FindNextFileA(file_handler, &file) == 0)
						break;

					if (!grep(file.cFileName, ".."))
					{
						if (!grep(file.cFileName, "."))
							get_files_directory(files, path + file.cFileName, extension, size);

						for (j = 0; j < size; j++)
						{
							add_data = false;

							if (grep(file.cFileName, extension[j], false))
							{
								add_data = true;
								break;
							}
						}

						if (add_data)
						{
							FileAndPath aux(file.cFileName, j, original_path);
							files.push(aux);
							i++;
						}
					}
				}

				FindClose(file_handler);
			}
		}
		catch (const std::exception & err)
		{
			std::cerr << "\tEXCEPTION IN READING FOLDER" << "\n\t\t" << err.what() << std::endl;
		}
	}

	int get_sizeof_gltype(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return 4;
		case GL_UNSIGNED_INT: return 4;
		case GL_UNSIGNED_BYTE: return 1;
		}

		return 0;
	}

	float random(unsigned int a, unsigned int b)
	{
		float result = 0.0f;
		float aux_a = a + 0.1;

		result = aux_a + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (b - aux_a)));

		return result;
	}
}