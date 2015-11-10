#include "ChessMan.h"

CHESSMAN::CHESSMAN(int r, int c)
{
	row = r;
	column = c;
}

int CHESSMAN::getRow()
{
	return row;
}

int CHESSMAN::getColumn()
{
	return column;
}

void CHESSMAN::setRow(int r)
{
	row = r;
}

void CHESSMAN::setColumn(int c)
{
	column = c;
}

bool CHESSMAN::isConfig(CHESSMAN & chessMan)
{
	return row == chessMan.getRow() ||
		column == chessMan.getColumn() ||
		abs(row - chessMan.getRow()) == abs(column - chessMan.getColumn());
}

void CHESSMAN::action(int offset)
{
	row = (row + offset) % SIZE;
}
