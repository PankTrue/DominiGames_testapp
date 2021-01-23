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
				offset.x += _cellSize.x;
				continue;
			}

			if (_board[j][i].getPieceType() == PieceType::White)
			{
				Piece::WhitePiece.setPosition(offset.x, offset.y);
				windowGame.Draw(Piece::WhitePiece);
			}
			else if (_board[j][i].getPieceType() == PieceType::Black)
			{
				Piece::BlackPiece.setPosition(offset.x, offset.y);
				windowGame.Draw(Piece::BlackPiece);
			}

			offset.x += _cellSize.x;
		}

		offset.x = _borderOffset.x;
		offset.y += _cellSize.y;
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
	
	float _x = ((x - _borderOffset.x) / _cellSize.x);
	float _y = ((y - _borderOffset.y) / _cellSize.y);

	if (_x >= 0 && _y >= 0 && _x <= 8 && _y <= 8)
	{
		if (std::abs(_x - static_cast<int>(_x)) <= 0.75f &&
			std::abs(_y - static_cast<int>(_y)) <= 0.75f)
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
		if (std::abs(static_cast<int>(destPos.x) - static_cast<int>(sourcePos.x)) == 1 &&
			std::abs(static_cast<int>(destPos.y) - static_cast<int>(sourcePos.y)) == 0 ||
			std::abs(static_cast<int>(destPos.x) - static_cast<int>(sourcePos.x)) == 0 &&
			std::abs(static_cast<int>(destPos.y) - static_cast<int>(sourcePos.y)) == 1)
		{
			this->MovePiece(destPiece, sourcePiece);
			return true;
		}
	}
	return false;
}

void BoardChess::CalcCellSizeAndBorderOffset(sf::Vector2u& windowSize)
{
	_cellSize.x = static_cast<float>(windowSize.x) / 9.0f;
	_cellSize.y = static_cast<float>(windowSize.y) / 9.0f;

	_borderOffset.x = static_cast<float>(windowSize.x) / 13.0f;
	_borderOffset.y = static_cast<float>(windowSize.y) / 15.0f;
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
