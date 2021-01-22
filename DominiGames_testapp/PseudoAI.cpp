#include "PseudoAI.h"
#include "Game.h"

void PseudoAI::Play(BoardChess& board, PieceType pieceType)
{
	while (true)
	{
		sf::Vector2u sourcePos;
		sf::Vector2u destPos;
		sourcePos.x = rand() % 8;
		sourcePos.y = rand() % 8;

		destPos = sourcePos;
		rand() % 2 == 0 ? destPos.x++ : destPos.y++;

		if (board.GetPieceByPosition(sourcePos)->getPieceType() == pieceType &&
			board.TryMovePiece(destPos, sourcePos))
			return;
	}
}
