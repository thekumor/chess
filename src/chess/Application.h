#pragma once

#include <chess/Window.h>
#include <chess/Buffer.h>
#include <chess/create.h>
#include <chess/Shader.h>
#include <chess/assert.h>
#include <chess/rect.h>
#include <chess/utility.h>
#include <glm/ext.hpp>
#include <string>

namespace chess {

	class Application
	{
	public:
		Application() = default;
		Application(const glm::uvec2& size, const std::string& title);

		void Run();
	private:
		chess::Window m_Window;
		glm::uvec2 m_Size = { 0, 0 };
		std::string m_Title = "";
	};

}