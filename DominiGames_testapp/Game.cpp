#include "Game.h"

Game::Game()
{
}

Game::~Game()
{

}

void Game::Init()
{
	_boardChess.SetImageBoard("./Resource/board.png");
	_windowGame.SetUp("Chess", { 800,800 });

	//while (_windowGame.IsOpen())
//	{
		_windowGame.GetWindowGame()->setFramerateLimit(60);
		_windowGame.BeginDraw();
		
		_windowGame.Draw(_boardChess.GetImageBoardSprite(_windowGame.GetWindowSize()));

		sf::Event e;
		while (_windowGame.GetWindowGame()->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				_windowGame.GetWindowGame()->close();
		}

		_windowGame.EndDraw();
		system("pause");
	//}




}

void Game::Start()
{
}



