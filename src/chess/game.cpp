#include "game.h"

namespace chess
{

	Game::Game(const Vec2& size, const std::string title)
		: m_Size(size), m_Title(title)
	{
	}

	int Game::Run()
	{
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			Message("Unable to initialize video");
			exit(-1);
		}

		Window window(m_Size, m_Title);
		SDL_Renderer* renderer = window.GetRenderer();

		Chessboard board(ObjectPos(64.0f, 64.0f), ObjectSize(96.0f, 96.0f), Color(255, 255, 255, 255), Color(10, 10, 10, 255));

		// White pieces
		m_Textures["white_pawn"] = Texture("images/pawn_white.png", renderer);
		m_Textures["white_knight"] = Texture("images/knight_white.png", renderer);
		m_Textures["white_bishop"] = Texture("images/bishop_white.png", renderer);
		m_Textures["white_rook"] = Texture("images/rook_white.png", renderer);
		m_Textures["white_queen"] = Texture("images/queen_white.png", renderer);
		m_Textures["white_king"] = Texture("images/king_white.png", renderer);

		// Black pieces
		m_Textures["black_pawn"] = Texture("images/pawn_black.png", renderer);
		m_Textures["black_knight"] = Texture("images/knight_black.png", renderer);
		m_Textures["black_bishop"] = Texture("images/bishop_black.png", renderer);
		m_Textures["black_rook"] = Texture("images/rook_black.png", renderer);
		m_Textures["black_queen"] = Texture("images/queen_black.png", renderer);
		m_Textures["black_king"] = Texture("images/king_black.png", renderer);

		Sprite pawn(ObjectPos(0.0f, 0.0f), ObjectSize(256.0f, 256.0f), Color(0, 0, 0, 255), &m_Textures["black_king"]);

		// Main loop
		while (!window.ShouldClose())
		{
			// Logic
			window.HandleEvents();

			// Clearing
			SDL_SetRenderDrawColor(renderer, 80, 40, 130, 255);
			SDL_RenderClear(renderer);

			// Drawing
			board.Draw(renderer);

			// Displaying
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}

		SDL_Quit();

		return 0;
	}

	Chessboard::Chessboard(const ObjectPos& pos, const ObjectSize& fieldSize, const Color& whiteColor, const Color& blackColor)
		: m_Pos(pos), m_Size(fieldSize)
	{
		for (std::int32_t i = 0; i < 64; i++)
		{
			bool isEven = i % 2 == 0;
			std::int32_t row = i / 8;
			std::int32_t column = i % 8;

			m_Board[i] = Rectangle(
				ObjectSize(pos.x + fieldSize.x * column, pos.y + fieldSize.y * row),
				ObjectPos(fieldSize.x, fieldSize.y),
				row % 2 == 0 ? (isEven ? whiteColor : blackColor) : (isEven ? blackColor : whiteColor)
			);
		}
	}

	void Chessboard::Draw(SDL_Renderer* renderer)
	{
		for (std::int32_t i = 0; i < 64; i++)
			m_Board[i].Draw(renderer);
	}

}