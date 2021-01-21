#include "BoardChess.h"

void BoardChess::SetImageBoard(const char* path)
{
	_boardTexture.loadFromFile(path);
}

sf::Sprite& BoardChess::GetImageBoardSprite(sf::Vector2u &windowSize)
{
	_boardSprite.setTexture(_boardTexture,true);

	_boardSprite.setScale(	windowSize.x / _boardSprite.getLocalBounds().width,
							windowSize.y / _boardSprite.getLocalBounds().height);

	return _boardSprite;
}
