/*

1024. Magic Island

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description

There are N cities and N-1 roads in Magic-Island. You can go from one city to any other. One road only connects two cities. One day, The king of magic-island want to visit the island from the capital. No road is visited twice. Do you know the longest distance the king can go.


Input


There are several test cases in the input
A test case starts with two numbers N and K. (1<=N<=10000, 1<=K<=N). The cities is denoted from 1 to N. K is the capital.

The next N-1 lines each contain three numbers X, Y, D, meaning that there is a road between city-X and city-Y and the distance of the road is D. D is a positive integer which is not bigger than 1000.
Input will be ended by the end of file.


Output

One number per line for each test case, the longest distance the king can go.


Sample Input
3 1
1 2 10
1 3 20


Sample Output
20

Problem Source

ZSUACM Team Member

思路：
郭老给出的提示是“树的遍历”
只是，我又忘记怎样从图里遍历树了，
这道题明显每两个节点间有且只有一边，且，没有回路
“
两两相连且边数比顶点数少一，明显是无环。
”
那么，如何构造出这棵树

每个点是一个类，每条边是一个类。
每个点可以有许多边。

这就是这棵树，再用随便一个数组或vector就可以存所有点，于是就保留了整棵树的资料。

这次是复习树的构造和遍历麽
*/

#include <iostream>
#include <vector>

class Edge
{
public:
	int destination;
	int dis;
};

class Node
{
public:
	int city;
	int disSum;
	bool visited;
	std::vector<Edge> leaf;
};

Node node;
Edge edge;
std::vector<Node> tree(10001, node);

void DFS(Node &root) {
	if (root.visited)
	{
		return;
	}

	// 不能返回根，只有一条路可以走
	root.visited = true;

	for (int i = 0; i < root.leaf.size(); i++)
	{
		Node &node = tree[root.leaf.at(i).destination];
		if (node.visited)
		{
			continue;
		}
		node.disSum = root.disSum + root.leaf.at(i).dis;
		DFS(node);
	}

}
int main() {

	int cityNum, capital;
	int cityX, cityY, disXToY;

	while (std::cin >> cityNum >> capital) {
		int max = 0;
		for (int i = 1; i <= 10000; i++)
		{
			tree[i].leaf.clear();
			tree[i].city = i;
		}

		// 把树的全部资料塞入vector。
		for (int i = 1; i < cityNum; i++)
		{
			std::cin >> cityX >> cityY >> disXToY;

			tree[cityX].disSum = 0;
			tree[cityX].visited = false;
			edge.destination = cityY;
			edge.dis = disXToY;
			tree[cityX].leaf.push_back(edge);

			tree[cityY].disSum = 0;
			tree[cityY].visited = false;
			edge.destination = cityX;
			edge.dis = disXToY;
			tree[cityY].leaf.push_back(edge);
		}

		// 深度优先遍历这棵树
		DFS(tree[capital]);

		for (int i = 1; i <= cityNum; i++)
		{
			if (tree[i].disSum > max)
				max = tree[i].disSum;
		}

		std::cout << max << std::endl;
	}

	return 0;
}

/*
我的测试用例如下：
8 5
5 3 5
5 4 6
5 6 7
3 1 2
3 2 1
3 7 100
2 8 3

这次还算简单，几次调试就accept了。
这次的经验总结：
调试的时候，不要随便乱改代码，要分析代码，如果代码导致实际运行结果与预想不一样，果断改！
*/