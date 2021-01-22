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

Piece* BoardChess::GetPieceByPosition(sf::Vector2u &pos)
{
	return &_board[pos.x][pos.y];
}

Piece* BoardChess::GetPieceByPosition(uint32_t x, uint32_t y)
{
	return &_board[x][y];
}

bool BoardChess::TryGetPiecePositionByCoordinates(int x, int y, sf::Vector2u &pos)
{
	sf::Vector2u result;
	
	float _x = ((x - _borderOffset.x) / _cellSize);
	float _y = ((y - _borderOffset.y) / _cellSize);

	if (_x >= 0 && _y >= 0 && _x <= 8 && _y <= 8)
	{
		if (std::abs(_x - (int)_x) <= 0.75f &&
			std::abs(_y - (int)_y) <= 0.75f)
		{
			pos.x = std::floor(_x);
			pos.y = std::floor(_y);
			return true;
		}
	}
	return false;
}

bool BoardChess::TryMovePiece(sf::Vector2u& destPos, sf::Vector2u& sourcePos)
{
	auto destPiece = GetPieceByPosition(destPos);
	auto sourcePiece = GetPieceByPosition(sourcePos);
	
	if (destPiece != sourcePiece &&
		destPos.x < 8 && destPos.y < 8 &&
		destPiece->getPieceType() == PieceType::Empty && 
		sourcePiece->getPieceType() != PieceType::Empty)
	{
		if (std::abs((int)destPos.x - (int)sourcePos.x) == 1 &&
			std::abs((int)destPos.y - (int)sourcePos.y) == 0 ||
			std::abs((int)destPos.x - (int)sourcePos.x) == 0 &&
			std::abs((int)destPos.y - (int)sourcePos.y) == 1)
		{
			this->MovePiece(destPiece, sourcePiece);
			return true;
		}
	}
	return false;
}

void BoardChess::MovePiece(Piece *dest, Piece *source)
{
	if(dest != NULL && source != NULL)
	{
		dest->setPieceType(source->getPieceType());
		source->setPieceType(PieceType::Empty);
	}
}


sf::Sprite& BoardChess::GetImageBoardSprite()
{
	return _boardSprite;
}
