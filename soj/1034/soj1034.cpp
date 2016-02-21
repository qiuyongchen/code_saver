/*
1034. Forest

Constraints

Time Limit : 1 secs, Memory Limit : 32 MB

Description


In the field of computer science, forest is important and deeply researched, it is a model for many data structures.Now it’s your job here to calculate the depth and width of given forests.

Precisely, a forest here is a directed graph with neither loop nor two edges pointing to the same node.Nodes with no edge pointing to are roots, we define that roots are at level 0.If there’s an edge points from node A to node B, then node B is called a child of node A, and we define that B is at level(k + 1) if and only if A is at level k .
We define the depth of a forest is the maximum level number of all the nodes, the width of a forest is the maximum number of nodes at the same level.

Input

There’re several test cases.For each case, in the first line there are two integer numbers n and m(1≤n≤100, 0≤m≤100, m≤n*n) indicating the number of nodes and edges respectively, then m lines followed, for each line of these m lines there are two integer numbers a and b(1≤a, b≤n)indicating there’s an edge pointing from a to b.Nodes are represented by numbers between 1 and n.n = 0 indicates end of input.

Output


For each case output one line of answer, if it’s not a forest, i.e.there’s at least one loop or two edges pointing to the same node, output “INVALID”(without quotation mark), otherwise output the depth and width of the forest, separated by a white space.


Sample Input
1 0
1 1
1 1
3 1
1 3
2 2
1 2
2 1
0 88


Sample Output
0 1
INVALID
1 2
INVALID


Problem Source

ZSUACM Team Member

思路：
    对图的处理，寻找图的宽度和深度
	用深度优先来寻找深度和判断“重边、同end边“

*/

#include <iostream>

int Graph[100][100];
int n, m;
int maxDepth, maxWidth;
bool visited[100], valid;
int inDegree[100];
int width[100];

int begin, end;

bool dfs(int node, int depth) {
	visited[node] = true;
	width[depth]++;

	maxDepth = maxDepth > depth ? maxDepth : depth;

	for (size_t i = 0; i < n; i++)
	{
		// 寻找node的子节点
		if (Graph[node][i] == 1) {
			// 子节点本应该没被访问过（如果被访问过，说明图中出现了环）
			if (visited[i])
			{
				return false;
			}
			if (!dfs(i, depth + 1))
			{
				return false;
			}
		}
	}

	return true;
}

int main() {
	while (std::cin >> n >> m && n != 0) {
		for (size_t i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				Graph[i][j] = 0;
			}
			visited[i] = false;
			inDegree[i] = 0;
			width[i] = 0;
		}
		maxDepth = maxWidth = 0;
		valid = true;

		for (size_t i = 0; i < m; i++)
		{
			std::cin >> begin >> end;
			Graph[--begin][--end] = 1;
			inDegree[end]++;
		}

		for (size_t i = 0; i < n; i++)
		{
			// 逐个找到根节点
			if (inDegree[i] == 0)
			{
				if (!dfs(i, 0))
					valid = false;
			}
		}

		for (size_t i = 0; i < n; i++)
		{
			if (!visited[i])
				valid = false;
		}

		for (size_t i = 0; i < 100; i++)
		{
			maxWidth = maxWidth > width[i] ? maxWidth : width[i];
		}

		if (valid)
		{
			std::cout << maxDepth << " " << maxWidth << "\n";
		}
		else
		{
			std::cout << "INVALID\n";
		}

	}

	return 0;
}