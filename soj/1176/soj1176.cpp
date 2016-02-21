/* *

1176. Two Ends
Constraints

Time Limit: 1 secs, Memory Limit: 64 MB
Description

In the two-player game "Two Ends", an even number of cards is laid out in a row. On each card, face up, is written a positive integer. Players take turns removing a card from either end of the row and placing the card in their pile. The player whose cards add up to the highest number wins the game. Now one strategy is to simply pick the card at the end that is the largest -- we'll call this the greedy strategy. However, this is not always optimal, as the following example shows: (The first player would win if she would first pick the 3 instead of the 4.)
3 2 10 4
You are to determine exactly how bad the greedy strategy is for different games when the second player uses it but the first player is free to use any strategy she wishes.
Input

There will be multiple test cases. Each test case will be contained on one line. Each line will start with an even integer n followed by n positive integers. A value of n = 0 indicates end of input. You may assume that n is no more than 1000. Furthermore, you may assume that the sum of the numbers in the list does not exceed 1,000,000.
Output

For each test case you should print one line of output of the form:
In game m, the greedy strategy might lose by as many as p points.
where m is the number of the game (starting at game 1) and p is the maximum possible difference between the first player's score and second player's score when the second player uses the greedy strategy. When employing the greedy strategy, always take the larger end. If there is a tie, remove the left end.
Sample Input

4 3 2 10 4
8 1 2 3 4 5 6 7 8
8 2 2 1 5 3 8 7 3
0

Sample Output

In game 1, the greedy strategy might lose by as many as 7 points.
In game 2, the greedy strategy might lose by as many as 4 points.
In game 3, the greedy strategy might lose by as many as 5 points.

思路：
    这种类型的题，似乎就是动态规划，两个人都取了一对数后，情况发生变化，player1的策略必须改变（毕竟player2的策略是死的）。
	那么，动态规划到底是什么玩意....
	
	状态和状态的改变
	
	什么叫改变？在运筹学里边，动态规划的意思不是说事物发展呈螺旋上升，会从一个状态转变到另一个状态吗？如果这样...
	
	这道题里的状态是哪个？
	如果把问题抽象化，应该是这样
	  设Fx为：MAX{玩家一选取左边的数/玩家二按greedy strategy取数/两人取到的数的差加上“剩下的数里两人逐渐拉开的差距”, 
	             玩家一选取右边的数/玩家二按greedy strategy取数/两人取到的数的差加上“剩下的数里两人逐渐拉开的差距”}
				 
	感觉有点像递归呀，你看，直接一个max函数，函数里头设两个变量，这两个变量又调用max函数（数组边界改变了），返回最大的那个。
	嗯，max函数的参数里，必须有一个数组，数组的头指针和尾指针，递归式调用的话，只要改变数组的头尾指针，这个方案似乎可行，
	不知道会不会超时或超内存，我先试试。
	
	
* */

/* *
#include <iostream>

int max(int a, int b)
{
	return a > b ? a : b;
}

int MAX(int a[], int index_head, int index_end)
{
	if (index_head == index_end)
	{
		return 0;
	}

	if (index_head + 1 == index_end)
	{
		return a[index_head] > a[index_end] ? a[index_head] - a[index_end] : a[index_end] - a[index_head];
	}
	
	int choose_left = 0, choose_right = 0;
	int player_one, player_two;
	int difference;
	
	// 玩家一选取左边的数/玩家二按greedy strategy取数/两人取到的数的差加上“剩下的数里两人逐渐拉开的差距”
	player_one = index_head;
	player_two = a[index_head + 1] > a[index_end] ? index_head + 1 : index_end;
	difference = a[player_one] - a[player_two];
	if (player_two == index_head + 1)
	{
		choose_left = difference + MAX(a, index_head + 2, index_end);
	}
	else
	{
		choose_left = difference + MAX(a, index_head + 1, index_end - 1);
	}

    // 玩家一选取右边的数/玩家二按greedy strategy取数/两人取到的数的差加上“剩下的数里两人逐渐拉开的差距”
	player_one = index_end;
	player_two = a[index_head] > a[index_end - 1] ? index_head : index_end - 1;
	difference = a[player_one] - a[player_two];
	if (player_two == index_head)
	{
		choose_right = difference + MAX(a, index_head + 1, index_end - 1);
	}
	else
	{
		choose_right = difference + MAX(a, index_head, index_end - 2);
	}
	
	return max(choose_left, choose_right);
}

int main()
{
	int N;
	int order = 1;
	int card_num[1000];
	
	std::cin >> N;
	while (N != 0)
	{
		// input all the cards.
		for (int i = 0; i < N; i++)
		{
			std::cin >> card_num[i];
		}
		
		std::cout << "In game " << order << ", the greedy strategy might lose by as many as "
		          << MAX(card_num, 0, N - 1) << " points.\n";
		std::cin >> N;
	}
	return 0;
}

* */

/* *
这个版本倒是通过几个样例，但是超时了，唉-_-。
我又去查了差，似乎动态规划的超时问题很普遍，一个替换方法是用数组代替递归，用数组来存储之前已经算出来的结果，这，好像有点麻烦...
不管了，今天先学习这动态规划，把递归版本和数组版本都打出来！
* */

#include <iostream>
#include <stdio.h>

int save[1001][1001];

int max(int a, int b)
{
	return a > b ? a : b;
}

int MAX(int a[], int index_head, int index_end, int save[][1001])
{

	if (index_end - index_head <= 1)
	{
		// save[index_head][index_end] = a[index_head] > a[index_end] ? 
		//                               a[index_head] - a[index_end] : a[index_end] - a[index_head];
		return a[index_end] > a[index_head] ? 
		                              a[index_end] - a[index_head] : a[index_head] - a[index_end];
	}
	
	if (save[index_head][index_end] != 9999999)
		return save[index_head][index_end];
		
	int choose_left = 0, choose_right = 0;
	int player_one, player_two;
	int difference;
	
	// 玩家一选取左边的数/玩家二按greedy strategy取数/两人取到的数的差加上“剩下的数里两人逐渐拉开的差距”
	player_one = index_head;
	player_two = a[index_head + 1] >= a[index_end] ? index_head + 1 : index_end;
	difference = a[player_one] - a[player_two];
	if (player_two == index_head + 1)
	{
		choose_left = difference + MAX(a, index_head + 2, index_end, save);
	}
	else
	{
		choose_left = difference + MAX(a, index_head + 1, index_end - 1, save);
	}

    // 玩家一选取右边的数/玩家二按greedy strategy取数/两人取到的数的差加上“剩下的数里两人逐渐拉开的差距”
	player_one = index_end;
	player_two = a[index_head] >= a[index_end - 1] ? index_head : index_end - 1;
	difference = a[player_one] - a[player_two];
	if (player_two == index_head)
	{
		choose_right = difference + MAX(a, index_head + 1, index_end - 1, save);
	}
	else
	{
		choose_right = difference + MAX(a, index_head, index_end - 2, save);
	}
	
	save[index_head][index_end] = max(choose_left, choose_right);
	
	return save[index_head][index_end];
}

int main()
{
	int N;
	int order = 1;
	int card_num[1005];
	
	std::cin >> N;
	while (N != 0)
	{
		// input all the cards.
		for (int i = 0; i < N; i++)
		{
			std::cin >> card_num[i];
			for (int j = 0; j < 1001; j++)
			{
				save[j][i] = 9999999;
			}
		}
		
		// std::cout << "In game " << order++ << ", the greedy strategy might lose by as many as "
		//           << MAX(card_num, 0, N - 1, save) << " points.\n";
		int d = MAX(card_num, 0, N - 1, save);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", order++, d);
		std::cin >> N;
	}
	return 0;
}

/* *
后记：
    相当无语，wrong answer了好多次，结果，是那条“If there is a tie, remove the left end.”
	我选择了右边，难怪一直错误。。。。
	我还在那里“非常嗨地”改数组的大小。。。。
	唉
* */