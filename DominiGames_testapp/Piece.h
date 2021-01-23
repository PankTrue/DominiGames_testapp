#pragma once

#include "SFML/Graphics.hpp"

enum PieceType
{
	White,
	Black,
	Empty
};


class Piece
{
public:
	Piece(PieceType pieceType);
	Piece();

	sf::Sprite* getPieceSprite();

	PieceType getPieceType();
	void setPieceType(PieceType type);

	bool getIsSelected();
	void setIsSelected(bool selected);


	static void InitPieces(std::string whitePiecePath, std::string blackPiecePath, float scaleX, float scaleY);

	static sf::Sprite WhitePiece;
	static sf::Sprite BlackPiece;

private:
	PieceType _pieceType;
	bool _isSelected;
};
