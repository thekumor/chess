#pragma once

// Chess
#include <chess/window.h>
#include <chess/vector.h>
#include <chess/object.h>

// SDL
#include <sdl3/sdl.h>

// STL
#include <string>

namespace chess
{

	class Game
	{
	public:
		Game(const Vec2& size, const std::string title);
		Game() = default;

		int Run();

	private:
		Vec2 m_Size;
		std::string m_Title;
	};

}