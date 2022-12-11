#include <chess/Application.h>

int main()
{
	chess::Application game(glm::vec2(1000, 720), "Chess");
	game.Run();
}