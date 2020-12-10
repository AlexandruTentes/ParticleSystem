#include "../lib/App.h"

namespace ParticleSystem
{
	void App::run()
	{
		DynamicObject<FileAndPath> files;
		get_files_directory(files, std::string(Global::get_instance().model_path), model_extension, sizeof(model_extension) / sizeof(model_extension[0]));
		FolderData::get_instance().files = files;

		while (display.running())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.5, 0.25, 0.5, 1.0);

			gui.update();

			glfwSwapBuffers(display.window);
			glfwPollEvents();
		}
	}
}