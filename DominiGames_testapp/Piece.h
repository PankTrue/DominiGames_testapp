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

	sf::Sprite* getPieceSprite();

	PieceType getPieceType();
	void setPieceType(PieceType type);

	bool getIsSelected();
	void setIsSelected(bool selected);

	static void InitPeaces(std::string whitePeacePath, std::string blackPeacePath, float scaleX, float scaleY);

	static sf::Sprite WhitePeace;
	static sf::Sprite BlackPeace;

private:
	PieceType _pieceType;
	bool _isSelected;


};
