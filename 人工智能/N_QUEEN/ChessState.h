#ifndef CHESSSTATE_H
#define CHESSSTATE_H

#include <list>
#include <time.h>
#include <vector>
#include "ChessMan.h"

#define SIZE 8
#define random(x) (rand()%x)

/*
棋盘的状态，包括
整个棋盘的评估值（评估值为0表示已经达到最优，各皇后的位置都正确），
棋盘的大小，
各个棋子是如何分布的，各个皇后在哪里，
从这个棋盘状态出发，移动一个皇后之后的棋盘状态的集合。

*/
class CHESS_STATE
{
public:
	double ddd = 0.001;

	int evalution; // 整个棋盘的评估值
	int size; // 棋盘的大小
	std::vector<CHESSMAN> chessMans; // 各个棋子的分布情况
	std::vector<CHESS_STATE> nextStates; // 移动一个皇后之后的棋盘状态的集合

	CHESS_STATE();

	CHESS_STATE(const CHESS_STATE & s);

	CHESS_STATE(std::vector<CHESSMAN> chessMans_);

	~CHESS_STATE();

	// 求整个棋盘的评估值
	int getEvalution();

	// 求移动一个皇后之后的棋盘状态的集合
	std::vector<CHESS_STATE> getNextStates();

	int getNextStatesSize();

	// 随机移动一个皇后后的棋盘状态
	CHESS_STATE getRandomState();

	int getSize();

	void setSize(int size_);

private:

};


#endif