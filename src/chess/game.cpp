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

		// Board settings
		const float boardLeft = 80.0f;
		const float boardUp = 100.0f;
		const float fieldSize = 90.0f;
		const Color white(255, 255, 255, 255);
		const Color gray(64, 64, 64, 255);

		// Fill in the board
		Rectangle board[64];
		for (std::int32_t i = 0; i < 64; i++)
		{
			bool isEven = i % 2 == 0;
			std::int32_t row = i / 8;
			std::int32_t column = i % 8;

			board[i] = Rectangle(
				Vector2<float>(boardLeft + fieldSize * column, boardUp + fieldSize * row),
				Vector2<float>(fieldSize, fieldSize),
				row % 2 == 0 ? (isEven ? white : gray) : (isEven ? gray : white)
			);
		}

		Texture testTexture = CreateTexture("images/test.bmp", renderer);
		Sprite testSprite({ 0, 0 }, { 20, 20 }, { 255, 0, 0, 255 }, &testTexture);

		// Main loop
		while (!window.ShouldClose())
		{
			// Logic
			window.HandleEvents();

			// Clearing
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			// Drawing
			for (std::int32_t i = 0; i < 64; i++)
				board[i].Draw(renderer);

			testSprite.Draw(renderer);

			// Displaying
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}

		SDL_Quit();

		return 0;
	}

}