#include "SteepestAscent.h"

SteepestAscent::SteepestAscent()
{
}

SteepestAscent::~SteepestAscent()
{
}

SteepestAscent::SteepestAscent(CHESS_STATE chessState)
{
	initState = chessState;
	stateGenerated = 0;
}

void SteepestAscent::resetState(CHESS_STATE chessState)
{
	initState = chessState;
	stateGenerated = 0;
}

// ¿ªÊ¼ÅÀÉ½
CHESS_STATE SteepestAscent::climbing()
{
	stateGenerated = 0;

	CHESS_STATE currentState = initState;
	std::vector<CHESS_STATE> nextState;
	bool flag = false;

	while (true)
	{
		flag = false;

		nextState.clear();
		nextState = currentState.getNextStates();
		stateGenerated += currentState.getNextStatesSize();

		for (int i = 0; i < nextState.size(); i++)
		{
			if (currentState.evalution > nextState[i].evalution) {
				currentState = nextState[i];
				flag = true;
			}
		}

		if (!flag) {
			return currentState;
		}
	}
}


