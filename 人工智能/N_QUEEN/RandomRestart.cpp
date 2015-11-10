#include "RandomRestart.h"

RandomRestart::RandomRestart()
{
}

RandomRestart::~RandomRestart()
{
}

RandomRestart::RandomRestart(CHESS_STATE chessState)
{
	initState = chessState;
	stateGenerated = 0;
	steepestAscenter = SteepestAscent(initState);
}

// ¿ªÊ¼ÅÀÉ½
CHESS_STATE RandomRestart::climbing()
{
	stateGenerated = 0;

	CHESS_STATE currentState = initState;
	CHESS_STATE newState;
	std::vector<CHESS_STATE> nextState;

	int evalution = currentState.getEvalution();

	while (evalution != 0)
	{
		newState = steepestAscenter.climbing();
		stateGenerated += steepestAscenter.stateGenerated;

		if (newState.getEvalution() < evalution)
		{
			currentState = newState;
			evalution = newState.getEvalution();
		}

		if (evalution == 0)
			return currentState;

		steepestAscenter.resetState(generator.getNewState());
	}
	return CHESS_STATE();
}
