#pragma once

#include <SFML/Graphics.hpp>


#include "Piece.h"
#include "WindowGame.h"


class BoardChess
{
public:
	void SetImageBoard(const char *path, WindowGame &window);

	void DrawPieces(WindowGame &windowGame);

	Piece *GetPieceByPosition(int x, int y);


	sf::Sprite &GetImageBoardSprite();

	Piece _board[8][8];

private:
	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;

	constexpr static int _cellSize = 90; 
	sf::Vector2f _borderOffset = { 55,48 };
};

