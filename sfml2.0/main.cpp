#include "game.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	Game game;
	while (game.running() && !game.get_end_game())
	{
		game.update();
		game.render();
	}
}