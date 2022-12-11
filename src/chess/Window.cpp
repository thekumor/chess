#include "Window.h"

namespace chess {

	Window::Window(const glm::uvec2& size, const std::string& title)
		: m_Size(size), m_Title(title)
	{
		CHESS_ASSERT(glfwInit());
		Create(size, title);
		Bind();

		glfwWindowHint(GLFW_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_VERSION_MAJOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		renderer::Initialize();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Create(const glm::uvec2& size, const std::string& title)
	{
		m_Size = size;
		m_Title = title;

		CHESS_ASSERT(m_Window = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr));
	}

	void Window::WaitEvents() const
	{
		glfwWaitEvents();
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::Bind()
	{
		glfwMakeContextCurrent(m_Window);
	}

}