#include "window.h"

namespace chess
{

	Window::Window(const Vec2& size, const std::string& title)
		: m_Closed(false), m_Size(size), m_Title(title)
	{
		m_Window = SDL_CreateWindow(title.c_str(), size.x, size.y, SDL_WINDOW_RESIZABLE);
		if (!m_Window)
		{
			Message("Unable to create window");
			exit(-2);
		}

		m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
		if (!m_Renderer)
		{
			Message("Unable to create renderer");
			exit(-3);
		}

		//HINSTANCE instance = reinterpret_cast<HINSTANCE>(GetModuleHandleA(nullptr));
		//HMENU menu = LoadMenuA(instance, MAKEINTRESOURCE(IDR_MENU1));
		//HWND windowHandle = nullptr;
		//SetMenu(windowHandle, menu);
	}
	
	SDL_Renderer* Window::GetRenderer()
	{
		return m_Renderer;
	}

	bool Window::ShouldClose() const
	{
		return m_Closed;
	}

	void Window::HandleEvents()
	{
		static SDL_Event eventData;

		while (SDL_PollEvent(&eventData))
		{
			switch (eventData.type)
			{
				case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
				{
					m_Closed = true;
				} break;
			}
		}
	}

}