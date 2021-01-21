#include "BoardChess.h"

void BoardChess::SetImageBoard(const char* path, WindowGame& window)
{
	_boardTexture.loadFromFile(path);

	_boardSprite.setTexture(_boardTexture);

	_boardSprite.setScale(window.GetWindowSize().x / _boardSprite.getLocalBounds().width,
		window.GetWindowSize().y / _boardSprite.getLocalBounds().height);
}

sf::Sprite& BoardChess::GetImageBoardSprite()
{
	return _boardSprite;
}
