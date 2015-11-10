#ifndef FIRSTCHOICE_H
#define FIRSTCHOICE_H

#include "ChessState.h"

class FirstChoice
{
public:
	FirstChoice();
	~FirstChoice();

	CHESS_STATE initState;
	int stateGenerated;

	FirstChoice(CHESS_STATE chessState);

	// ¿ªÊ¼ÅÀÉ½
	CHESS_STATE climbing();
private:

};

#endif