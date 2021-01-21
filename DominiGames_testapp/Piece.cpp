#include "Piece.h"

sf::Sprite Piece::WhitePeace;
sf::Sprite Piece::BlackPeace;

Piece::Piece() : _pieceType(PieceType::Empty), _isSelected(false) { }

sf::Sprite* Piece::getPieceSprite()
{
	if (_pieceType == PieceType::Black)
		return &BlackPeace;
	else if (_pieceType == PieceType::White)
		return &WhitePeace;
	else return NULL;
}

Piece::Piece(PieceType peaceType) : _pieceType(peaceType), _isSelected(false){ }

PieceType Piece::getPieceType()
{
	return _pieceType;
}

void Piece::setPieceType(PieceType type)
{
	_pieceType = type;
}

bool Piece::getIsSelected()
{
	return _isSelected;
}

void Piece::setIsSelected(bool selected)
{
	_isSelected = selected;
}




void Piece::InitPeaces(std::string whitePiecePath, std::string blackPiecePath, float scaleX, float scaleY)
{
	static sf::Texture blackTexture, whiteTexture;

	blackTexture.loadFromFile(blackPiecePath);
	whiteTexture.loadFromFile(whitePiecePath);
	BlackPeace.setTexture(blackTexture);
	WhitePeace.setTexture(whiteTexture);

	BlackPeace.setScale(scaleX, scaleY);
	WhitePeace.setScale(scaleX, scaleY);
}
