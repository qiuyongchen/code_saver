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

CHESS_STATE::CHESS_STATE(std::vector<int> chessMans_)
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

	int wide = (int)sqrt(SIZE * 1.0);
	/*
	for (int i = chessMans.size() - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (chessMans[i] != 0 && chessMans[j] != 0) {
				evalution += (calculateLinearConflict(
					i / wide, i % wide,
					j / wide, j % wide,
					(chessMans[i]) / wide, (chessMans[i]) % wide,
					(chessMans[j]) / wide, (chessMans[j]) % wide) ? 1 : 0);
			}
		}
	}
	*/

	for (int i = chessMans.size() - 1; i >= 0; i--) {
		evalution += 2 * calculateManhattanDistance(
			(chessMans[i]) / wide, (chessMans[i]) % wide, i / wide, i % wide);
	}

	return evalution;

}

bool CHESS_STATE::calculateLinearConflict(int ai, int aj, int bi, int bj,
	int aGoalI, int aGoalJ, int bGoalI, int bGoalJ) {
	double k, b;
	// first, judge whether the 4 points are in one line
	// second, judege whether the vector(ai - bi, aj - bj)
	// and the vector(aGoalI - bGoalI, aGoalJ - bGoalJ) is in contrast
	// i = k * j + b
	if (aj != bj) {
		k = (1.0 * ai - bi) / (aj - bj);
		b = ai - aj * k;
		if (isTheSame(aGoalI - aGoalJ * k, b) && isTheSame(bGoalI - bGoalJ * k, b)) {
			// yes, the 4 points are in one line
			double v1i = ai - bi, v1j = aj - bj;
			double v2i = aGoalI - bGoalI, v2j = aGoalJ - bGoalJ;
			return isTheSame(
				(v1i * v2i + v1j * v2j) /
				sqrt((v1i * v1i + v1j * v1j) * (v2i * v2i + v2j * v2j)), -1);

		}
	}
	else {
		if (aGoalJ == aj && bGoalJ == bj) {
			// yes, the 4 points are in one line
			double v1i = ai - bi, v1j = aj - bj;
			double v2i = aGoalI - bGoalI, v2j = aGoalJ - bGoalJ;
			return isTheSame(
				(v1i * v2i + v1j * v2j) /
				sqrt((v1i * v1i + v1j * v1j) * (v2i * v2i + v2j * v2j)), -1);
		}
	}
	return false;
}

bool CHESS_STATE::isTheSame(double a, double b) { return abs(a - b) <= ddd; }

int CHESS_STATE::calculateManhattanDistance(int ai, int aj, int bi, int bj) {
	return abs(ai - bi) + abs(aj - bj);
}

// 求移动一个皇后之后的棋盘状态的集合
std::vector<CHESS_STATE> CHESS_STATE::getNextStates()
{
	nextStates.clear();

	int wide = (int)sqrt(SIZE * 1.0);
	int blankPositionI = 0;
	int blankPositionJ = 0;

	for (int i = chessMans.size() - 1; i >= 0; i--) {
		if (chessMans[i] == 0) {
			blankPositionI = i / wide;
			blankPositionJ = i % wide;
			break;
		}
	}

	if (blankPositionI > 0) {
		// can move up
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[(blankPositionI - 1) * wide + blankPositionJ];
		tempMans[(blankPositionI - 1) * wide + blankPositionJ] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		nextStates.push_back(node);
	}

	if (blankPositionI < wide - 1) {
		// can move down
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[(blankPositionI + 1) * wide + blankPositionJ];
		tempMans[(blankPositionI + 1) * wide + blankPositionJ] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		nextStates.push_back(node);
	}

	if (blankPositionJ > 0) {
		// can move left
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[blankPositionI * wide + blankPositionJ - 1];
		tempMans[blankPositionI * wide + blankPositionJ - 1] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		nextStates.push_back(node);
	}

	if (blankPositionI < wide - 1) {
		// can move right
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[blankPositionI * wide + blankPositionJ + 1];
		tempMans[blankPositionI * wide + blankPositionJ + 1] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		nextStates.push_back(node);
	}

	return nextStates;
}

int CHESS_STATE::getNextStatesSize()
{
	return nextStates.size();
}

CHESS_STATE CHESS_STATE::getRandomState()
{
	int wide = (int)sqrt(SIZE * 1.0);
	int blankPositionI = 0;
	int blankPositionJ = 0;

	for (int i = chessMans.size() - 1; i >= 0; i--) {
		if (chessMans[i] == 0) {
			blankPositionI = i / wide;
			blankPositionJ = i % wide;
			break;
		}
	}

	std::vector<int> direction;

	if (blankPositionI > 0) {
		// can move up
		direction.push_back(0);
	}
	if (blankPositionI < wide - 1) {
		// can move down
		direction.push_back(1);
	}
	if (blankPositionJ > 0) {
		// can move left
		direction.push_back(2);
	}
	if (blankPositionI < wide - 1) {
		// can move right
		direction.push_back(3);
	}

	int choice = (rand() % direction.size());

	if (direction.at(choice)  == 0)
	{
		// can move up
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[(blankPositionI - 1) * wide + blankPositionJ];
		tempMans[(blankPositionI - 1) * wide + blankPositionJ] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		return node;
	}
	else if (direction.at(choice) == 1)
	{
		// can move down
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[(blankPositionI + 1) * wide + blankPositionJ];
		tempMans[(blankPositionI + 1) * wide + blankPositionJ] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		nextStates.push_back(node);
		return node;
	}
	else if (direction.at(choice) == 2)
	{
		// can move left
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[blankPositionI * wide + blankPositionJ - 1];
		tempMans[blankPositionI * wide + blankPositionJ - 1] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		nextStates.push_back(node);
		return node;
	}
	else if (direction.at(choice) == 3)
	{
		// can move right
		std::vector<int> tempMans = chessMans;

		int temp = tempMans[blankPositionI * wide + blankPositionJ];
		tempMans[blankPositionI * wide + blankPositionJ]
			= tempMans[blankPositionI * wide + blankPositionJ + 1];
		tempMans[blankPositionI * wide + blankPositionJ + 1] = temp;
		CHESS_STATE node = CHESS_STATE(tempMans);
		node.getEvalution();
		nextStates.push_back(node);
		return node;
	}

	return CHESS_STATE();
}

int CHESS_STATE::getSize()
{
	return size;
}

void CHESS_STATE::setSize(int size_)
{
	size = size_;
}
