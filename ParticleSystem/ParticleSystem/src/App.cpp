#include "../lib/App.h"

namespace ParticleSystem
{
	void App::run()
	{
		Shader shader;
		shader.load_shaders();
		shader.compile_shaders();

		//Loading the model data
		Model m;
		read_raw_model(m);

		//Loading the vertex buffer
		VertexBuffer vb;
		vb.load(m.vertex);
		vb.generate_buffers();

		//Loading the index buffer
		IndexBuffer ib;
		ib.load(m.index);
		ib.generate_buffers();

		//Loading the layout
		VertexBufferLayout layout;
		layout.load(GL_FLOAT, 3);	//Vertex layout
		//layout.load(GL_FLOAT, 4);

		//Preparing the vertex array
		VertexArray va;
		va.add_buffer(&vb, &ib, &layout);
		ib.bind();

		Matrix4d<float> view(0, 0, -3, 0,
			0, 0, 1, 0,
			0, 1, 0, 0,
			0, 0, 0, 0);

		while (display.running())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.5, 0.25, 0.5, 1.0);

			shader.bind();

			glm::mat4 get_transformation = get_transformation_matrix(temporary_globals::get_instance().scale,
				temporary_globals::get_instance().translation, TO_RAD(temporary_globals::get_instance().rotation_x),
				TO_RAD(temporary_globals::get_instance().rotation_y), TO_RAD(temporary_globals::get_instance().rotation_z));

			glm::mat4 get_perspective = get_perspective_matrix(70.0f, 
				(float) Global::get_instance().window_width / Global::get_instance().window_height, 0.01f, 1000.0f);

			glm::mat4 get_view = get_view_matrix(get_perspective, view);

			glm::mat4 get_mat = get_calc_matrix(get_transformation, get_view);

			//std::cout << "model: \n" << get_transformation.print() << "\n";

			shader.set_uniform_matrix4fv("transform", get_mat);

			glDrawElements(GL_TRIANGLES, m.index.vertex.get_size(), GL_UNSIGNED_INT, nullptr);

			gui.update();

			glfwSwapBuffers(display.window);
			glfwPollEvents();
		}
	}
}