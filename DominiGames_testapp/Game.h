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

	void Init();
	void Start();


	void DrawSelectedPiece();
	bool CheckGameEnd();

	
private:
	void InputHandle();

	
	BoardChess		_boardChess;
	WindowGame		_windowGame;
	PseudoAI		_pseudoAI;
	GameQueueStep	_gameQueueStep;
	sf::Event		e;
	Piece*			selectedPiece = NULL;
	sf::Vector2u	selectedPos;


	constexpr static PieceType _playerPieceType = PieceType::White;
	constexpr static PieceType _AIPieceType = PieceType::Black;
};


