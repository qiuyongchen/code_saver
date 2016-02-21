/*

1152. 简单的马周游问题

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB , Special Judge

Description


在一个5 * 6的棋盘中的某个位置有一只马，如果它走29步正好经过除起点外的其他位置各一次，这样一种走法则称马的周游路线，试设计一个算法，从给定的起点出发，找出它的一条周游路线。

为了便于表示一个棋盘，我们按照从上到下，从左到右对棋盘的方格编号，如下所示：

1     2     3       4     5     6

7     8     9       10    11       12

13    14       15    16       17    18

19    20       21    22       23    24

25    26       27    28       29    30
马的走法是“日”字形路线，例如当马在位置15的时候，它可以到达2、4、7、11、19、23、26和28。但是规定马是不能跳出棋盘外的，例如从位置1只能到达9和14。

Input

输入有若干行。每行一个整数N(1<=N<=30)，表示马的起点。最后一行用-1表示结束，不用处理。

Output

对输入的每一个起点，求一条周游线路。对应地输出一行，有30个整数，从起点开始按顺序给出马每次经过的棋盘方格的编号。相邻的数字用一个空格分开。

Sample Input
4
-1


Sample Output
注意：如果起点和输入给定的不同，重复多次经过同一方格或者有的方格没有被经过，都会被认为是错误的。

Problem Source

ZSUACM Team Member

思路：
    和郭老PPT所说一致，使用回溯算法

	数据结构定义如下：
	struct position{int x,int y} 位置记录
	position direction[8] 记录马的下一步方向
	bool ifPassed[5][6] 记录马是否走过该位置
	int passSum 马已经走的步数，到了29步即成功周游
	int passDate[5][6] 马走过该位置的时间，用于输出
	position start 马的起始位置

	bool ifFound 是否已经找到了周游解，用于决定递归的继续和暂停

	递归算法原理，
	如果已经找到解，直接返回，否则，
	先确定下一步的位置，
	如果位置在棋盘内而且没有被走过，那么
	    标记该位置（ifPassed = true passSum++ passDate = passSum），
		表示已经走过该位置
		如果passSum == 29，则找到解，ifFind = true
		否则递归该位置
		反标记该位置（ifPassed = false passSum-- passDate = -1）
	结束算法

	先试试
*/

#include <iostream>

struct position
{
	int x;
	int y;
	position() {}
	position(int a, int b) { x = a; y = b; }
};

position direction[8] = {
	position(1, -2), position(2, -1),
	position(2, 1), position(1, 2),
	position(-1, 2), position(-2, 1),
	position(-2, -1), position(-1, -2)
};

bool ifPassed[5][6];
int passSum;
int passDate[5][6];
position output[30];
position start;
bool ifFound;

void DFS(position now) {
	if (ifFound)
		return;

	position next;
	for (int i = 0; i < 8; i++)
	{
		next.x = now.x + direction[i].x;
		next.y = now.y + direction[i].y;
		if (ifPassed[next.x][next.y])
			continue;
		if (next.x >= 0 && next.x < 5 && next.y >= 0 && next.y < 6)
		{
			ifPassed[next.x][next.y] = true;
			passSum++;
			// passDate[next.x][next.y] = passSum;
			output[passSum] = next;

			if (passSum == 29)
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
		start.y = (N - 1) % 6;
		start.x = (N - 1) / 6;

		passSum = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 6; j++) {
				ifPassed[i][j] = false;
				// passDate[i][j] = -1;
			}

		passSum = 0;
		ifPassed[start.x][start.y] = true;
		passDate[start.x][start.y] = 0;
		output[0] = start;
		ifFound = false;
		
		DFS(start);

		for (int i = 0; i < 30; i++)
		{
			if (i == 0)
			{
				std::cout << output[i].x * 6 + output[i].y + 1;
			}
			else
			{
				std::cout << " " << output[i].x * 6 + output[i].y + 1;
			}
		}
		std::cout << std::endl;

		std::cin >> N;
	}
	return 0;
}

/*
后记：
    这马周游问题还算是简单，递归回溯（深度优先）
*/