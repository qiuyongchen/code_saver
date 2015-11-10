#ifndef CHESSSTATEGENERATOR_H
#define CHESSSTATEGENERATOR_H

#include "ChessState.h"
#define random(x) (rand()%x)

// 棋盘状态制造者
class ChessStateGenerator
{
public:
	ChessStateGenerator();
	~ChessStateGenerator();

	// 随机产生一个棋盘状态
	CHESS_STATE getNewState();
private:

};

#endif