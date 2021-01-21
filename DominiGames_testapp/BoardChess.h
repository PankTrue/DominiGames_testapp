#pragma once

#include <SFML/Graphics.hpp>


#include "Piece.h"
#include "WindowGame.h"


class BoardChess
{
public:
	void SetImageBoard(const char *path, WindowGame &window);

	sf::Sprite &GetImageBoardSprite();

	Piece _board[8][8];

private:
	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;
};

