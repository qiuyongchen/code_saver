#include <iostream>

#include "ChessState.h"
#include "ChessStateGenerator.h"
#include "FirstChoice.h"
#include "SimulatedAnnealing.h"
#include "SteepestAscent.h"
#include "RandomRestart.h"

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define CASE 1000
#define CASEF 1000.0

void simulatedAnnealing() {
	ChessStateGenerator generator;

	/* simulatedAnnealing *************************************************/
	double simulatedAnnealingStateGenerated = 0;
	int simulatedAnnealingPass = 0;
	double simulatedAnnealingPassRate = 0;
	double simulatedAnnealingMin = 9999999;
	double simulatedAnnealingMax = 0;
	double simulatedAnnealingAve = 0;

	std::cout << "it will take a few seconds to get the result, please wait for a moment.\n";

	for (int i = 0; i < CASE; i++)
	{
		CHESS_STATE initState = generator.getNewState();

		SimulatedAnnealing simulatedAnnealing = SimulatedAnnealing(initState);

		CHESS_STATE finalState = simulatedAnnealing.climbing(100, 1);
		if (finalState.evalution == 0)
		{
			std::cout << "case " << i << " found**************\n";
			simulatedAnnealingPass++;
		}
		std::cout << "case " << i << " done\n";
		simulatedAnnealingStateGenerated += simulatedAnnealing.stateGenerated;
		simulatedAnnealingMin = MIN(simulatedAnnealingMin, simulatedAnnealing.stateGenerated);
		simulatedAnnealingMax = MAX(simulatedAnnealingMax, simulatedAnnealing.stateGenerated);
	}
	simulatedAnnealingPassRate = simulatedAnnealingPass / CASEF;
	simulatedAnnealingAve = simulatedAnnealingStateGenerated / CASEF;

	std::cout << "Data about simulatedAnnealing:";
	std::cout << "\nTotal states generated: " << simulatedAnnealingStateGenerated
		<< "\nMin states: " << simulatedAnnealingMin
		<< "\nMax states: " << simulatedAnnealingMax
		<< "\nAve states: " << simulatedAnnealingAve
		<< "\nTotal Pass caes in 1000 case: " << simulatedAnnealingPass
		<< "\nPass rate: " << simulatedAnnealingPassRate
		<< "\n\n";
}

void randomRestart() {
	ChessStateGenerator generator;

	/* randomRestart *************************************************/
	double randomRestartStateGenerated = 0;
	int randomRestartPass = 0;
	double randomRestartPassRate = 0;
	double randomRestartMin = 9999999;
	double randomRestartMax = 0;
	double randomRestartAve = 0;

	std::cout << "it will take a few seconds to get the result, please wait for a moment.\n";

	for (int i = 0; i < CASE; i++)
	{
		CHESS_STATE initState = generator.getNewState();

		RandomRestart randomRestart = RandomRestart(initState);

		if (randomRestart.climbing().getEvalution() == 0)
		{
			randomRestartPass++;
		}
		randomRestartStateGenerated += randomRestart.stateGenerated;
		randomRestartMin = MIN(randomRestartMin, randomRestart.stateGenerated);
		randomRestartMax = MAX(randomRestartMax, randomRestart.stateGenerated);
	}
	randomRestartPassRate = randomRestartPass / CASEF;
	randomRestartAve = randomRestartStateGenerated / CASEF;

	std::cout << "Data about randomRestart:";
	std::cout << "\nTotal states generated: " << randomRestartStateGenerated
		<< "\nMin states: " << randomRestartMin
		<< "\nMax states: " << randomRestartMax
		<< "\nAve states: " << randomRestartAve
		<< "\nTotal Pass caes in 1000 case: " << randomRestartPass
		<< "\nPass rate: " << randomRestartPassRate
		<< "\n\n";
}

void firstChoice() {
	ChessStateGenerator generator;

	/* firstChoice *************************************************/
	int firstChoiceStateGenerated = 0;
	int firstChoicePass = 0;
	float firstChoicePassRate = 0;
	int firstChoiceMin = 9999999;
	int firstChoiceMax = 0;
	float firstChoiceAve = 0;

	std::cout << "it will take a few seconds to get the result, please wait for a moment.\n";

	for (int i = 0; i < CASE; i++)
	{
		CHESS_STATE initState = generator.getNewState();

		FirstChoice firstChoice = FirstChoice(initState);

		if (firstChoice.climbing().getEvalution() == 0)
		{
			firstChoicePass++;
		}
		firstChoiceStateGenerated += firstChoice.stateGenerated;
		firstChoiceMin = MIN(firstChoiceMin, firstChoice.stateGenerated);
		firstChoiceMax = MAX(firstChoiceMax, firstChoice.stateGenerated);
	}
	firstChoicePassRate = firstChoicePass / CASEF;
	firstChoiceAve = firstChoiceStateGenerated / CASEF;

	std::cout << "Data about firstChoice:";
	std::cout << "\nTotal states generated: " << firstChoiceStateGenerated
		<< "\nMin states: " << firstChoiceMin
		<< "\nMax states: " << firstChoiceMax
		<< "\nAve states: " << firstChoiceAve
		<< "\nTotal Pass caes in 1000 case: " << firstChoicePass
		<< "\nPass rate: " << firstChoicePassRate
		<< "\n\n";
}

void steepestAscent() {
	ChessStateGenerator generator;

	/* steepestAscent *************************************************/
	int steepestAscentStateGenerated = 0;
	int steepestAscentPass = 0;
	float steepestAscentPassRate = 0;
	int steepestAscentMin = 9999999;
	int steepestAscentMax = 0;
	float steepestAscentAve = 0;

	std::cout << "it will take a few seconds to get the result, please wait for a moment.\n";

	for (int i = 0; i < CASE; i++)
	{
		CHESS_STATE initState = generator.getNewState();

		SteepestAscent steepestAscent = SteepestAscent(initState);

		if (steepestAscent.climbing().getEvalution() == 0)
		{
			steepestAscentPass++;
		}
		steepestAscentStateGenerated += steepestAscent.stateGenerated;
		steepestAscentMin = MIN(steepestAscentMin, steepestAscent.stateGenerated);
		steepestAscentMax = MAX(steepestAscentMax, steepestAscent.stateGenerated);
	}
	steepestAscentPassRate = steepestAscentPass / CASEF;
	steepestAscentAve = steepestAscentStateGenerated / CASEF;

	std::cout << "Data about steepestAscent:";
	std::cout << "\nTotal states generated: " << steepestAscentStateGenerated
		<< "\nMin states: " << steepestAscentMin
		<< "\nMax states: " << steepestAscentMax
		<< "\nAve states: " << steepestAscentAve
		<< "\nTotal Pass caes in 1000 case: " << steepestAscentPass
		<< "\nPass rate: " << steepestAscentPassRate
		<< "\n\n";
}


int main() {
//	simulatedAnnealing();

	firstChoice();

	steepestAscent();

	randomRestart();


	return 0;
}

