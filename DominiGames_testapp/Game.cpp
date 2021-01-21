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
			_boardChess._board[j][i].setPieceType(PieceType::Black);

	for (int i = 7; i > 4; i--)
		for (int j = 7; j > 4; j--)
			_boardChess._board[j][i].setPieceType(PieceType::White);



	sf::Event e;
	Piece *selectedPiece = NULL;

	while (_windowGame.IsOpen())
	{
		_windowGame.BeginDraw();

		_windowGame.Draw(_boardChess.GetImageBoardSprite()); //draw background


		//draw pieces
		_boardChess.DrawPieces(_windowGame);



		if (selectedPiece != NULL && selectedPiece->getIsSelected())
		{

			auto mousePosition = sf::Mouse::getPosition(*(sf::Window *)(_windowGame.GetWindowGame()));
			auto piece = selectedPiece->getPieceSprite();
			if (piece != NULL)
			{
				piece->setPosition(mousePosition.x - 25, mousePosition.y - 25);
				_windowGame.Draw(*piece);
			}
		}
		

		while (_windowGame.GetWindowGame()->pollEvent(e))
		{
			if (e.type == sf::Event::MouseButtonReleased)
			{
				if (selectedPiece != NULL)
				{
					selectedPiece->setIsSelected(false);
					selectedPiece = NULL;
				}
			}
			else if (e.type == sf::Event::MouseButtonPressed)
			{
				selectedPiece = _boardChess.GetPieceByPosition(e.mouseButton.x, e.mouseButton.y);
				if (selectedPiece != NULL)
				{
					selectedPiece->setIsSelected(true);
				}
			}
			else if (e.type == sf::Event::Closed)
			{
				_windowGame.GetWindowGame()->close();
			}
		}
			
		_windowGame.EndDraw();
	}




}

void Game::Start()
{
}



