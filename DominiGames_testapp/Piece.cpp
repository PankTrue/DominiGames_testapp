#include "Piece.h"

sf::Sprite Piece::WhitePeace;
sf::Sprite Piece::BlackPeace;

Piece::Piece() : _pieceType(PieceType::Empty)
{

}

PieceType Piece::getPieceType()
{
	return _pieceType;
}

void Piece::setPieceType(PieceType type)
{
	_pieceType = type;
}

Piece::Piece(PieceType peaceType) : _pieceType(peaceType)
{

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
