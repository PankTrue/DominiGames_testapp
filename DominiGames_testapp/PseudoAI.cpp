#include "PseudoAI.h"
#include "Game.h"

void PseudoAI::Play(BoardChess& board, PieceType pieceType)
{
	Piece *selectedPiece;
	
	while (true)
	{
		sf::Vector2u sourcePos;
		sf::Vector2u destPos;
		sourcePos.x = rand() % 8;
		sourcePos.y = rand() % 8;

		selectedPiece = board.GetPieceByPosition(sourcePos);

		if(selectedPiece->getPieceType() != pieceType)
			continue;

		destPos = sourcePos;

		if (sourcePos.y < 5 && sourcePos.x >= 6)
			destPos.x--;
		else if (sourcePos.y >= 6 && sourcePos.x < 5)
			destPos.y--;
		else
			rand() % 2 == 0 ? destPos.x++ : destPos.y++;

		
		if ( board.TryMovePiece(destPos, sourcePos))
			return;
	}
}
