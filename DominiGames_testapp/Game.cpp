#include "Game.h"

Game::Game()
{
}

Game::~Game()
{

}

void Game::Init()
{
	_windowGame.SetUp("Chess", { 800,800 });
	_windowGame.GetWindowGame()->setFramerateLimit(60);


	_boardChess.SetImageBoard("Resource/board.png", _windowGame);
	Piece::InitPeaces("Resource/w_pawn.png","Resource/b_pawn.png",0.6,0.6);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_boardChess._board[i][j].setPieceType(PieceType::Black);

	for (int i = 7; i > 4; i--)
		for (int j = 7; j > 4; j--)
			_boardChess._board[i][j].setPieceType(PieceType::White);



	sf::Event e;

	while (_windowGame.IsOpen())
	{
		_windowGame.BeginDraw();

		_windowGame.Draw(_boardChess.GetImageBoardSprite()); //draw background


		//draw pieces
		sf::Vector2f offset = { 56,50 };

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (_boardChess._board[i][j].getPieceType() == PieceType::White)
				{
					Piece::WhitePeace.setPosition(offset.x,offset.y);
					_windowGame.Draw(Piece::WhitePeace);
				}
				else if (_boardChess._board[i][j].getPieceType() == PieceType::Black)
				{
					Piece::BlackPeace.setPosition(offset.x, offset.y);
					_windowGame.Draw(Piece::BlackPeace);
				}
				offset.x += 90;
			}
			offset.x = 50;
			offset.y += 89;
		}



		while (_windowGame.GetWindowGame()->pollEvent(e))
		{
			if (e.type == sf::Event::MouseButtonPressed)
			{
				std::cout << e.mouseButton.x << " | " << e.mouseButton.y << std::endl;
				continue;
			}
			else if (e.type == sf::Event::Closed)
			{
				_windowGame.GetWindowGame()->close();
			}
		}
			
		_windowGame.EndDraw();

		//sf::sleep(sf::milliseconds(100));
	}



	//}




}

void Game::Start()
{
}



