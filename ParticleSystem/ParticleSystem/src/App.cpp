#include "../lib/App.h"

namespace ParticleSystem
{
	void App::run()
	{
		srand((float)time(NULL));

		DynamicObject<FileAndPath> files;
		get_files_directory(files, std::string(Global::get_instance().model_path), model_extension, sizeof(model_extension) / sizeof(model_extension[0]));
		FolderData::get_instance().files = files;

		ParticlePhysics::init_particle_data();

		while (display.running())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.26, 0.28, 0.41, 1.0);

			gui.update();

			glfwSwapBuffers(display.window);
			glfwPollEvents();
		}
	}
}