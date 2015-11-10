#ifndef RANDOMRESTART_H
#define RANDOMRESTART_H

#include "ChessStateGenerator.h"
#include "SteepestAscent.h"

class RandomRestart
{
public:
	RandomRestart();
	~RandomRestart();

	SteepestAscent steepestAscenter; // 在随机重新启动爬山算法中的爬山人
	ChessStateGenerator generator;
	CHESS_STATE initState;
	int stateGenerated;

	RandomRestart(CHESS_STATE chessState);

	// 开始爬山
	CHESS_STATE climbing();
private:

};

#endif