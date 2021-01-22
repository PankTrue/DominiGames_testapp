#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>

#include "Game.h"

int main()
{
	srand(time(0));
	
	Game g;
	
	g.Init();

    return 0;
}