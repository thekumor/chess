#include "Application.h"

namespace chess {

	Application::Application(const glm::uvec2& size, const std::string& title)
		: m_Size(size), m_Title(title), m_Window(size, title)
	{

	}

	void Application::Run()
	{
		chess::Rect test;
		test.SetColor(glm::uvec4(0, 0, 255, 255));
		test.SetPosition(glm::vec2(100, 100));
		test.SetSize(glm::vec2(200, 200));

		Program prog = chess::create::NewProgram("src/chess/shader/basic.shader");

		// Positions
		CHESS_CHECK_ERROR(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0));
		CHESS_CHECK_ERROR(glEnableVertexAttribArray(0));

		// Colors
		CHESS_CHECK_ERROR(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(2 * sizeof(float))));
		CHESS_CHECK_ERROR(glEnableVertexAttribArray(1));

		while (!m_Window.ShouldClose())
		{
			m_Window.WaitEvents();
			m_Window.SwapBuffers();

			// Drawing
			prog.Bind();
			renderer::Clear(glm::vec4(0.05f, 0.05f, 0.05f, 1.0f));
			test.Draw();
		}
	}

}