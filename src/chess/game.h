#pragma once

// Chess
#include <chess/window.h>
#include <chess/vector.h>
#include <chess/object.h>

// SDL
#include <sdl3/sdl.h>

// STL
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

namespace chess
{

	class Chessboard
	{
	public:
		Chessboard(const ObjectPos& pos, const ObjectSize& fieldSize, const Color& whiteColor, const Color& blackColor);
		Chessboard() = default;

		void Draw(SDL_Renderer* renderer);

	private:
		std::unordered_map<std::string, Rectangle*> m_Fields;
		Rectangle m_Board[64];
		ObjectPos m_Pos;
		ObjectSize m_Size;
	};

	class Game
	{
	public:
		Game(const Vec2& size, const std::string title);
		Game() = default;

		int Run();

	private:
		Vec2 m_Size;
		std::string m_Title;
		std::unordered_map<std::string, Texture> m_Textures;
		std::vector<std::shared_ptr<Sprite>> m_Sprites;
	};

}