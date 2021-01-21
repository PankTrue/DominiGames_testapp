#pragma once

#include "BoardChess.h"
#include "WindowGame.h"

#include <SFML/Graphics.hpp>


class Game
{
public:
	Game();
	~Game();

	void Init();
	void Start();

	
private:
	BoardChess _boardChess;
	WindowGame _windowGame;

};


