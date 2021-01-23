#include "Game.h"

Game::Game()
{
	_gameQueueStep = static_cast<GameQueueStep>(rand() % 2);
	selectedPiece = NULL;
}
Game::~Game(){ }


void Game::Init(sf::Vector2u windowSize)
{
	_windowGame.SetUp(_title, windowSize);
	_windowGame.GetWindowGame()->setFramerateLimit(60);

	_boardChess.CalcCellSizeAndBorderOffset(_windowGame.GetWindowSize());
	
	_boardChess.SetImageBoard("Resource/board.png", _windowGame);
	
	Piece::InitPieces("Resource/w_pawn.png","Resource/b_pawn.png",
		_windowGame.GetWindowSize().x / 1500.0f, _windowGame.GetWindowSize().y / 1400.0f);
}

void Game::FillBoard()
{
	//fill black pieces
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_boardChess.GetPieceByPosition(j, i)->setPieceType(PieceType::Black);

	//fill white pieces
	for (int i = 7; i > 4; i--)
		for (int j = 7; j > 4; j--)
			_boardChess.GetPieceByPosition(j, i)->setPieceType(PieceType::White);
}

void Game::Start()
{

	while (_windowGame.IsOpen())
	{
		if (_gameQueueStep == GameQueueStep::AI)
		{
			_pseudoAI.Play(_boardChess, _AIPieceType);
			_gameQueueStep = GameQueueStep::Player;
		}

		_windowGame.BeginDraw();

		_windowGame.Draw(_boardChess.GetImageBoardSprite()); //draw background

		_boardChess.DrawPieces(_windowGame);

		this->DrawSelectedPiece();
		this->InputHandle();

		_windowGame.EndDraw();
	}
}

void Game::DrawSelectedPiece()
{
	if (selectedPiece != NULL && selectedPiece->getIsSelected())
	{
		auto mousePosition = sf::Mouse::getPosition(*static_cast<sf::Window*>(_windowGame.GetWindowGame()));
		auto piece = selectedPiece->getPieceSprite();
		if (piece != NULL)
		{
			piece->setPosition(	mousePosition.x - static_cast<float>(_windowGame.GetWindowSize().x) / 32.0f,
								mousePosition.y - static_cast<float>(_windowGame.GetWindowSize().y) / 32.0f);
			_windowGame.Draw(*piece);
		}
	}
}

bool Game::CheckGameEnd()
{
	bool whiteWon = false;
	bool blackWon = false;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (_boardChess.GetPieceByPosition(j, i)->getPieceType() == PieceType::White)
			{
				whiteWon = true;
			}
			else
			{
				whiteWon = false;
				break;
			}
		if (!whiteWon)
			break;
	}
	

	for (int i = 7; i > 4; i--)
	{
		for (int j = 7; j > 4; j--)
			if (_boardChess.GetPieceByPosition(j, i)->getPieceType() == PieceType::Black)
			{
				blackWon = true;
			}
			else
			{
				blackWon = false;
				break;
			}
		if (!blackWon)
			break;
	}

	if(whiteWon)
	{
		std::cout << "White Won!" << std::endl;
		return true;
	}
	if(blackWon)
	{
		std::cout << "Black Won!" << std::endl;
		return true;
	}
	return false;
}

void Game::InputHandle()
{
	while (_windowGame.GetWindowGame()->pollEvent(e))
	{
		if (e.type == sf::Event::MouseButtonReleased)
		{
			if (selectedPiece != NULL && selectedPiece->getIsSelected())
			{
				if (selectedPiece->getPieceType() == _playerPieceType)
				{
					sf::Vector2u destPos;
					if (_boardChess.TryGetPiecePositionByCoordinates(e.mouseButton.x, e.mouseButton.y, destPos))
					{
						if (_boardChess.TryMovePiece(destPos, selectedPos))
						{
							std::cout << "Moved to: " << destPos.x << "|" << destPos.y << std::endl;
							_gameQueueStep = GameQueueStep::AI;

							if (this->CheckGameEnd())
							{
								std::cout << "Game end!" << std::endl;
								_windowGame.Destroy();
							}
						}
					}
				}
				selectedPiece->setIsSelected(false);
			}
		}
		else if (e.type == sf::Event::MouseButtonPressed)
		{
			if (_boardChess.TryGetPiecePositionByCoordinates(e.mouseButton.x, e.mouseButton.y, selectedPos))
			{
				selectedPiece = _boardChess.GetPieceByPosition(selectedPos);
				selectedPiece->setIsSelected(true);
			}
		}
		else if (e.type == sf::Event::Resized)
		{
			std::cout << "Resize: " << e.size.height << " | " << e.size.width << std::endl;
			this->Init({ e.size.width, e.size.height });
		}
		else if (e.type == sf::Event::Closed)
		{
			_windowGame.GetWindowGame()->close();
		}
	}
}




