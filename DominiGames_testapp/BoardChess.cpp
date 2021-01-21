#include "BoardChess.h"

void BoardChess::SetImageBoard(const char* path, WindowGame& window)
{
	_boardTexture.loadFromFile(path);

	_boardSprite.setTexture(_boardTexture);

	_boardSprite.setScale(window.GetWindowSize().x / _boardSprite.getLocalBounds().width,
		window.GetWindowSize().y / _boardSprite.getLocalBounds().height);
}

void BoardChess::DrawPieces(WindowGame &windowGame)
{
	sf::Vector2f offset = _borderOffset;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (_board[j][i].getIsSelected())
			{
				offset.x += _cellSize;
				continue;
			}

			if (_board[j][i].getPieceType() == PieceType::White)
			{
				Piece::WhitePeace.setPosition(offset.x, offset.y);
				windowGame.Draw(Piece::WhitePeace);
			}
			else if (_board[j][i].getPieceType() == PieceType::Black)
			{
				Piece::BlackPeace.setPosition(offset.x, offset.y);
				windowGame.Draw(Piece::BlackPeace);
			}

			offset.x += _cellSize;
		}

		offset.x = _borderOffset.x;
		offset.y += _cellSize;
	}

}

Piece* BoardChess::GetPieceByPosition(int x, int y)
{
	float _x = ((x - _borderOffset.x) / _cellSize);
	float _y = ((y - _borderOffset.y) / _cellSize);

	if (_x >= 0 && _y >= 0 && _x <= 8 && _y <= 8)
	{
		if (std::abs(_x - (int)_x) <= 0.7f && 
			std::abs(_y - (int)_y) <= 0.7f)
		{
			std::cout << std::floor(_x) << "|" << std::floor(_y) << std::endl;
			return &_board[(int)std::floor(_x)][(int)std::floor(_y)];
		}
	}
	return NULL;
}


sf::Sprite& BoardChess::GetImageBoardSprite()
{
	return _boardSprite;
}
