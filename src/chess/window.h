#pragma once

// Chess
#include <chess/vector.h>
#include <chess/util.h>
#include <chess/resource.h>

// SDL
#include <sdl3/sdl.h>

// WinAPI
#include <windows.h>

// STL
#include <string>
#include <cstdlib>

namespace chess
{

	class Window
	{
	public:
		Window(const Vec2& size, const std::string& title);
		Window() = default;

		SDL_Renderer* GetRenderer();
		bool ShouldClose() const;
		void HandleEvents();

	private:
		bool m_Closed;
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
		Vec2 m_Size;
		std::string m_Title;
	};

}