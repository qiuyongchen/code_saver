/**

1156. Binary tree

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

Your task is very simple: Given a binary tree, every node of which contains one upper case character (‘A’ to ‘Z’); you just need to print all characters of this tree in pre-order.


Input


Input may contain several test data sets.

For each test data set, first comes one integer n (1 <= n <= 1000) in one line representing the number of nodes in the tree. Then n lines follow, each of them contains information of one tree node. One line consist of four members in order: i (integer, represents the identifier of this node, 1 <= i <= 1000, unique in this test data set), c (char, represents the content of this node described as above, ‘A’ <= c <= ‘Z’), l (integer, represents the identifier of the left child of this node, 0 <=  l <= 1000, note that when l is 0 it means that there is no left child of this node), r (integer, represents the identifier of the right child of this node, 0 <=  r <= 1000, note that when r is 0 it means that there is no right child of this node). These four members are separated by one space.

Input is ended by EOF.

You can assume that all inputs are valid. All nodes can form only one valid binary tree in every test data set.


Output

For every test data set, please traverse the given tree and print the content of each node in pre-order. Characters should be printed in one line without any separating space.


Sample Input
3
4 C 1 3
1 A 0 0
3 B 0 0
1
1000 Z 0 0
3
1 Q 0 2
2 W 3 0
3 Q 0 0


Sample Output
CAB
Z
QWQ


Problem Source

ZSUACM Team Member

思路：
先序遍历二叉树，这，额，好像做过很多次了。
但这里首先需要构造二叉树才行。
像这道题里面，只给出一个节点和该节点的左右孩子，这该怎么玩？
不知树根的话，一切都是扯蛋啊
这里的关键就是怎么样找树根了
用一个数组来存储节点，加入一个节点的时候，顺便告诉系统，它的左右孩子不是根！
每一个节点用一个struct表示，struct里边，除了那四个外，还有一个变量，用来判断是不是根，
另设一个变量判断是否是树中的节点。
*/

#include <iostream>

struct Node
{
	int identifier;
	char content;
	int Left;
	int Right;
	bool isRoot;
	bool inTree;
}allNodes[1001];

void traverPre(int n) {
	if (!allNodes[n].inTree)
	{
		return;
	}
	std::cout << allNodes[n].content;
	traverPre(allNodes[n].Left);
	traverPre(allNodes[n].Right);
}

int main() {
	int N = 0;
	int identifier_ = 0;
	char content_ = 0;
	int Left_ = 0;
	int Right_ = 0;

	while (std::cin >> N)
	{
		// 切记要初始化struct数组，不然无法用！！
		for (int i = 0; i < 1001; i++)
		{
			allNodes[i].identifier = i;
			allNodes[i].content = 0;
			allNodes[i].Left = 0;
			allNodes[i].Right = 0;
			allNodes[i].inTree = false;
			allNodes[i].isRoot = true;
		}

		// 得到树的所有信息
		for (int i = 0; i < N; i++)
		{
			std::cin >> identifier_ >> content_ >> Left_ >> Right_;
			
			allNodes[identifier_].identifier = identifier_;
			allNodes[identifier_].content = content_;
			allNodes[identifier_].Left = Left_;
			allNodes[identifier_].Right = Right_;
			allNodes[identifier_].inTree = true;

			if (Left_ != 0)
			{
				allNodes[Left_].isRoot = false;
			}
			if (Right_ != 0)
			{
				allNodes[Right_].isRoot = false;
			}
		}

		// 寻找树根并开始遍历
		for (int i = 0; i < 1001; i++)
		{
			if (allNodes[i].inTree && allNodes[i].isRoot)
			{
				traverPre(i);
				std::cout << std::endl;
				break;
			}
		}


	}
	return 0;
}

/***************************
后记：
复习
    1.struct必须有个初始化的过程，不然直接声明数组的话是用不了的。
	2.其实也不是，在新一点的编译器（比如vs2015）中，可以把struct当作类，直接在struct内部初始化struct的，但
	  西西里那“xp系统”，是不能这么做的，只能在外部逐个赋值。
	3.struct数组实在是太特殊了，不，是奇葩，必须初始赋值才能访问。
	4.刚才我又试了几下，西西里确实xp，它要求struct必须初始化。而vs2015不需要，而且vs2015可以把struct当作类

************************/