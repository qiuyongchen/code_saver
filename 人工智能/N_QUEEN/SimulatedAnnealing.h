#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include <cmath>
#include "ChessState.h"

#define random(x) (rand()%x)

class SimulatedAnnealing
{
public:
	SimulatedAnnealing();

	~SimulatedAnnealing();

	CHESS_STATE initState;
	int stateGenerated;

	SimulatedAnnealing(CHESS_STATE chessState);

	// ¿ªÊ¼Ä£ÄâÍË»ð
	CHESS_STATE climbing(double temperator, double sche);
private:

};

#endif