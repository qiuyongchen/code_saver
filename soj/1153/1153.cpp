/*

  注：我照搬了soj1152马周游的代码，在没有经过任何修改的情况下，严重超时（至少我至今没跑出一个解）
  现在需要优化一下，优化的方案，也就是所谓的“往某个方向走后，能继续走的方向越少，小马哥越喜欢”，
  比如往上走后，还能走4个方向，往下走后，还能走3个方向，小马哥优先走下边。

*/

#include <iostream>

// 位置坐标
struct position
{
	int x;
	int y;
	int Heuristic; // 小马哥在该位置能走的的方向的数量
	position() {}
	position(int a, int b) { x = a; y = b; Heuristic = 0; }
};

// 小马哥能走的方向相对于当前位置的offset
position direction[8] = {
	position(1, -2), position(2, -1),
	position(2, 1), position(1, 2),
	position(-1, 2), position(-2, 1),
	position(-2, -1), position(-1, -2)
};

bool ifPassed[8][8]; // 记录整个棋盘的“经过情况”
int passSum;
position output[64];
position start;
bool ifFound; // 是否已经找到解的标志

// 启发函数，评估值是各个方向的“后续可走方向”的数量
int getHeuristic(position pos) {
	int Heuristic = 0;
	int i = 8;
	for (int i = 0; i < 8; i++)
	{
		if (pos.x + direction[i].x >= 0 && pos.x + direction[i].x < 8 && pos.y + direction[i].y >= 0 && pos.y + direction[i].y < 8)
		{
			Heuristic++;
		}
	}
	return Heuristic;
}

void DFS(position now) {
	if (ifFound)
		return;

	// 调用启发函数来评估各个方向
	for (int i = 0; i < 8; i++)
	{
		direction[i].Heuristic = getHeuristic(position(now.x + direction[i].x, now.y + direction[i].y));
	}

	// 把评估值最小的方向放前面，优先走
	position temp;
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 8; j++) {
			if (direction[i].Heuristic > direction[j].Heuristic)
			{
				temp = direction[i];
				direction[i] = direction[j];
				direction[j] = temp;
			}
		}
	}

	// 小马哥逐个方向地走（当然，还得看该方向能否走，不然就撞墙或“重蹈覆辙”了）
	position next;
	for (int i = 0; i < 8; i++)
	{
		next.x = now.x + direction[i].x;
		next.y = now.y + direction[i].y;

		// 如果小马哥已经走过该方向
		if (ifPassed[next.x][next.y])
			continue;

		// 确保没有撞墙
		if (next.x >= 0 && next.x < 8 && next.y >= 0 && next.y < 8)
		{
			ifPassed[next.x][next.y] = true;
			passSum++;
			output[passSum] = next;

			if (passSum == 63)
			{
				ifFound = true;
				continue;
			}

			DFS(next);
			if (ifFound)
				return;
			ifPassed[next.x][next.y] = false;
			passSum--;
			// passDate[next.x][next.y] = -1;
		}
	}
}

int main() {
	int N;


	std::cin >> N;
	while (N != -1)
	{
		start.y = (N - 1) % 8;
		start.x = (N - 1) / 8;

		passSum = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				ifPassed[i][j] = false;
				// passDate[i][j] = -1;
			}

		passSum = 0;
		ifPassed[start.x][start.y] = true;
		output[0] = start;
		ifFound = false;

		DFS(start);

		for (int i = 0; i < 64; i++)
		{
			if (i == 0)
			{
				std::cout << output[i].x * 8 + output[i].y + 1;
			}
			else
			{
				std::cout << " " << output[i].x * 8 + output[i].y + 1;
			}
		}
		std::cout << std::endl;

		std::cin >> N;
	}
	return 0;
}

/*
 后记：居然可以一次就过，怎么可以这样...
       我仅是挑选了后续可扩展方向最少的方向而已，居然瞬间将几分钟算不出的解给搞出来了，算法真是一种神奇的东西。
	   事实上，这个算法的做法，是让马沿着棋盘的边缘走，逐渐走到棋盘的中心，某种程度上是启发式算法。
	   评估函数是计算后续可扩展步数。
*/