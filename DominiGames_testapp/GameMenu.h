#pragma once

enum StateMenu
{
	PLAY_GAME,
	EXIT_GAME,
	WAIT,
};

static const std::string StateMenuStr[] = { "Play game", "Exit" };



class GameMenu
{
public:
	GameMenu();
	~GameMenu();

	StateMenu WaitSelecting();


private:

};

