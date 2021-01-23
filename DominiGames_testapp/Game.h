#pragma once

#include "BoardChess.h"
#include "WindowGame.h"
#include "PseudoAI.h"

#include <SFML/Graphics.hpp>

enum GameQueueStep
{
	Player,
	AI
};

class Game
{
public:
	Game();
	~Game();

	void Init(sf::Vector2u windowSize = {800,800 });
	void FillBoard();
	void Start();


	
private:
	void InputHandle();
	void DrawSelectedPiece();
	bool CheckGameEnd();

	
	BoardChess		_boardChess;
	WindowGame		_windowGame;
	PseudoAI		_pseudoAI;
	GameQueueStep	_gameQueueStep;
	sf::Event		e;
	Piece*			selectedPiece;
	sf::Vector2u	selectedPos;


	constexpr static PieceType _playerPieceType = PieceType::White;
	constexpr static PieceType _AIPieceType = PieceType::Black;

	const char *_title = "PseudoChess for DominiGames";
};


