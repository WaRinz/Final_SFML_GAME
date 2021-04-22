#include"Game.h"
#include<stdlib.h>
#include<time.h>


int main()
{
	srand(time(0));

	Game game;

	game.run();

	// end game
	return 0;
}