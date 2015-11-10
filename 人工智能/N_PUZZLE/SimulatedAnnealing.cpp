#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing()
{
}

SimulatedAnnealing::~SimulatedAnnealing()
{
}

SimulatedAnnealing::SimulatedAnnealing(CHESS_STATE chessState)
{
	initState = chessState;
	stateGenerated = 0;
}

// 开始模拟退火
CHESS_STATE SimulatedAnnealing::climbing(double temperator_, double sche)
{
	stateGenerated = 0;
	CHESS_STATE currentState = initState;
	CHESS_STATE newState;

	double temperator = temperator_;
	double d;
	double probability;
	double randProbability;

	while (currentState.evalution != 0 && temperator > 0)
	{
		// 随机选择一个新状态
		newState = currentState.getRandomState();
		stateGenerated++;

		d = currentState.evalution - newState.evalution;
		if (d > 0)
		{
			currentState = newState;
		}
		else
		{
			probability = exp(d / temperator);

			randProbability = random(10000) / 10000.0;
			// 如果概率百分百，那么0到1之内的数都中；
			// 如果概率只有百分之十，那么0到0.1之内的数才中
			if (randProbability <= probability)
			{
				currentState = newState;
			}
		}

		temperator -= sche; // 逐渐退火
	}
	return currentState;
}
