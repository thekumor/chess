#pragma once

#include <chess/assert.h>
#include <chess/renderer.h>
#include <glfw/glfw3.h>
#include <glm/vec2.hpp>
#include <string>

namespace chess {

	class Window
	{
	public:
		Window() = default;
		Window(const glm::uvec2& size, const std::string& title);
		~Window();

		bool ShouldClose() const;
		void Create(const glm::uvec2& size, const std::string& title);
		void WaitEvents() const;
		void SwapBuffers();
		void Bind();
	private:
		GLFWwindow* m_Window = nullptr;
		glm::uvec2 m_Size = { 0, 0 };
		std::string m_Title = "";
	};

}