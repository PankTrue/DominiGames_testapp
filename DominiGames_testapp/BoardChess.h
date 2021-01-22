#pragma once

#include <SFML/Graphics.hpp>


#include "Piece.h"
#include "WindowGame.h"


class BoardChess
{
public:
	void SetImageBoard(const char *path, WindowGame &window);

	void DrawPieces(WindowGame &windowGame);

	Piece *GetPieceByPosition(sf::Vector2u& pos);
	Piece *GetPieceByPosition(uint32_t x, uint32_t y);
	sf::Sprite &GetImageBoardSprite();

	bool TryGetPiecePositionByCoordinates(int x, int y, sf::Vector2u &pos);
	bool TryMovePiece(sf::Vector2u &destPos, sf::Vector2u &sourcePos);

private:
	Piece _board[8][8];
	void MovePiece(Piece* dest, Piece* source);


	
	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;

	constexpr static int _cellSize = 90; 
	sf::Vector2f _borderOffset = { 55,48 };
};

