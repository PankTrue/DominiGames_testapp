#include "Piece.h"

sf::Sprite Piece::WhitePiece;
sf::Sprite Piece::BlackPiece;

Piece::Piece() : _pieceType(PieceType::Empty), _isSelected(false) { }

sf::Sprite* Piece::getPieceSprite()
{
	if (_pieceType == PieceType::Black)
		return &BlackPiece;
	else if (_pieceType == PieceType::White)
		return &WhitePiece;
	else return NULL;
}

Piece::Piece(PieceType pieceType) : _pieceType(pieceType), _isSelected(false){ }

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




void Piece::InitPieces(std::string whitePiecePath, std::string blackPiecePath, float scaleX, float scaleY)
{
	static sf::Texture blackTexture, whiteTexture;

	blackTexture.loadFromFile(blackPiecePath);
	whiteTexture.loadFromFile(whitePiecePath);
	BlackPiece.setTexture(blackTexture);
	WhitePiece.setTexture(whiteTexture);

	BlackPiece.setScale(scaleX, scaleY);
	WhitePiece.setScale(scaleX, scaleY);
}
