#define STB_IMAGE_IMPLEMENTATION

// Chess
#include <chess/game.h>
#include <chess/vector.h>

// STL
#include <iostream>
#include <cstdint>
#include <sdl3/sdl.h>

// Window stuff
#define CHESS_WIDTH 980
#define CHESS_HEIGHT 870
#define CHESS_TITLE "Chess"

int main()
{
	chess::Game chess(Vec2(CHESS_WIDTH, CHESS_HEIGHT), CHESS_TITLE);
	return chess.Run();
}