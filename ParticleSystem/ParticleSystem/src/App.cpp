#include "../lib/App.h"

namespace ParticleSystem
{
	void App::run()
	{
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