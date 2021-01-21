#pragma once

#include <SFML/Graphics.hpp>


#include "SlotBoard.h"


class BoardChess
{
public:
	void SetImageBoard(const char *path);
	sf::Sprite& GetImageBoardSprite(sf::Vector2u& windowSize);


private:
	SlotBoard _board[8][8];


	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;


};

