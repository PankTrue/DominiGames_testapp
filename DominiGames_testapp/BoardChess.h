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

	void CalcCellSizeAndBorderOffset(sf::Vector2u &windowSize);

private:
	Piece _board[8][8];
	void MovePiece(Piece* dest, Piece* source);

	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;

	sf::Vector2f _cellSize;
	sf::Vector2f _borderOffset;
};

