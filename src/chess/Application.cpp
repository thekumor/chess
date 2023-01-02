#include "Application.h"

namespace chess {

	Application::Application(const glm::uvec2& size, const std::string& title)
		: m_Size(size), m_Title(title), m_Window(size, title)
	{

	}

	void Application::Run()
	{
		Program prog = chess::create::NewProgram("src/chess/shader/basic.shader");

		chess::Rect test;
		test.SetColor(glm::uvec4(0, 0, 255, 255));
		test.SetPosition(glm::vec2(0, 0));
		test.SetSize(glm::vec2(200, 200));

		// Positions
		int32_t aPos = glGetAttribLocation(prog.GetIdentifier(), "aPos");
		CHESS_CHECK_ERROR(glVertexAttribPointer(aPos, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0));
		CHESS_CHECK_ERROR(glEnableVertexAttribArray(aPos));

		// Colors
		int32_t aColor = glGetAttribLocation(prog.GetIdentifier(), "aColor");
		CHESS_CHECK_ERROR(glVertexAttribPointer(aColor, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(2 * sizeof(float))));
		CHESS_CHECK_ERROR(glEnableVertexAttribArray(aColor));

		chess::Rect test2;
		test2.SetColor(glm::uvec4(0, 255, 0, 255));
		test2.SetPosition(glm::vec2(500, 500));
		test2.SetSize(glm::vec2(200, 200));

		while (!m_Window.ShouldClose())
		{
			m_Window.WaitEvents();
			m_Window.SwapBuffers();

			// Drawing
			prog.Bind();
			renderer::Clear(glm::vec4(0.05f, 0.05f, 0.05f, 1.0f));
			test.Draw();
			test2.Draw();
		}
	}

}