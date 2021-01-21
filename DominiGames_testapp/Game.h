#pragma once

#include "BoardChess.h"
#include "WindowGame.h"


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


