#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <list>
#include <math.h>
#define SIZE 8

/*
 棋子
*/
class CHESSMAN
{
public:
	int row;
	int column;

	CHESSMAN() {}
	~CHESSMAN() {}

	CHESSMAN(int r, int c);

	int getRow();

	int getColumn();

	void setRow(int r);

	void setColumn(int c);

	// 两个皇后之间是否冲突
	bool isConfig(CHESSMAN & chessMan);

	// 某一列的皇后向下移动offset个格子
	void action(int offset);

private:

};

#endif