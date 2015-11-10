#include "ChessState.h"

CHESS_STATE::CHESS_STATE()
{
	evalution = 99999999;
	size = SIZE;
}

CHESS_STATE::CHESS_STATE(const CHESS_STATE & s)
{
	evalution = s.evalution;
	size = s.size;
	chessMans = s.chessMans;
}

CHESS_STATE::CHESS_STATE(std::vector<CHESSMAN> chessMans_)
{
	chessMans = chessMans_;
	evalution = getEvalution();
	size = SIZE;
}

CHESS_STATE::~CHESS_STATE()
{
}

// 求整个棋盘的评估值
int CHESS_STATE::getEvalution()
{
	evalution = 0;

	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (chessMans[i].isConfig(chessMans[j])) {
				evalution++;
			}
		}
	}

	return evalution;
}

// 求移动一个皇后之后的棋盘状态的集合
std::vector<CHESS_STATE> CHESS_STATE::getNextStates()
{
	nextStates.clear();

	for (int i = 0; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			nextStates.push_back(CHESS_STATE(*this));
			nextStates.back().chessMans[i].action(j);
			nextStates.back().getEvalution();
		}
	}
	return nextStates;
}

int CHESS_STATE::getNextStatesSize()
{
	return nextStates.size();
}

CHESS_STATE CHESS_STATE::getRandomState()
{
	int c = rand() % (SIZE);
	int r = (rand() % (SIZE - 1)) + 1;

	CHESS_STATE newState(*this);
	newState.chessMans[c].action(r);
	newState.getEvalution();

	return newState;
}

int CHESS_STATE::getSize()
{
	return size;
}
