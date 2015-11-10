#include "ChessStateGenerator.h"

ChessStateGenerator::ChessStateGenerator()
{
}

ChessStateGenerator::~ChessStateGenerator()
{
}

// 随机产生一个棋盘状态
CHESS_STATE ChessStateGenerator::getNewState()
{
	CHESS_STATE state;
	int temp;
	bool exits = false;

	for (int i = 0; i < state.size; i++)
	{
		while (true)
		{
			exits = false;
			temp = random(state.size);

			for (std::vector<int>::iterator i = state.chessMans.begin(); i != state.chessMans.end(); i++)
			{
				if (*i == temp)
				{
					exits = true;
					break;
				}
			}

			if (!exits)
			{
				state.chessMans.push_back(temp);
				break;
			}
		}
	}

	state.getEvalution();

	return state;
}
