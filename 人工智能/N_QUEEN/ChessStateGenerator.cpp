#include "ChessStateGenerator.h"

ChessStateGenerator::ChessStateGenerator()
{
}

ChessStateGenerator::~ChessStateGenerator()
{
}

// 随机产生一个棋盘状态
CHESS_STATE ChessStateGenerator::getNewState()
{
	srand((int)time(0));
	CHESS_STATE state;

	for (int i = 0; i < state.getSize(); i++)
	{
		state.chessMans.push_back(CHESSMAN(random(state.getSize()), i));
	}
	// state.breakTheChessMan(state.chessMans);

	state.getEvalution();

	return state;
}
