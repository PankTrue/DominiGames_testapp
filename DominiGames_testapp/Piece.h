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
	Piece(PieceType peaceType);
	Piece();

	PieceType getPieceType();
	void setPieceType(PieceType type);

	static void InitPeaces(std::string whitePeacePath, std::string blackPeacePath, float scaleX, float scaleY);

	static sf::Sprite WhitePeace;
	static sf::Sprite BlackPeace;

private:
	PieceType _pieceType;


};
