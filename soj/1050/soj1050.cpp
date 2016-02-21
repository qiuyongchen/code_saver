/*************************

1050. Numbers & Letters


Constraints

Time Limit: 3 secs, Memory Limit: 32 MB


Description

In the early 80’s, a popular TV show on Dutch television was ‘Cijfers en Letters’ (Numbers and Letters). This game consisted of two game elements, in which the main goal was to outclass your opponent. Letters is a game in which you are given a number of letters with which you should form the longest Dutch word possible. Since Dutch is a very hard language to learn we will postpone implementation of this game element until after the contest.
For the second game element ‘Numbers’ 5 different numbers are chosen, together with a target number. The aim is to use some arithmetic on (some of) the five numbers to form the target number. Each number can be used only once. It might not be possible to form the target number given the input numbers, in that case the largest number smaller than the target number that can be calculated should be given. The only mathematical operations allowed are: +, -, *, /.  All intermediate results should be integers, so division is not always allowed (e.g. (2*2)/4 is OK, but 2*(2/4) is not).
Examples:
- If the 5 numbers are 1, 2, 3, 7 and 100 and the target number is 573, the target number can be reached as follows: (((100-1)*2)-7)*3. -If the 5 numbers are 3, 26, 78, 12 and 17, and the target number is 30, the target number can be reached as follows: (78*3)-(12*17).
- If the 5 numbers are 67, 69, 58, 22, 2, and the target number is 929, the target number cannot be reached, but the largest number smaller than the target number that can be reached is 923 = (22-(67-58))*(69+2).
Your assignment is to write a program that calculates the best approximation from below of the target number using arithmetic on the 5 given numbers. Note that if it is not possible to reach the exact number, you should give the largest reachable number below the target number.


Input

The first line contains the number of runs, N. The next N lines consist of six numbers separated by a space. The first 5 numbers Mi, 1≤Mi≤100, are the numbers you can use to calculate the target number. The sixth number is the target number T, 0≤T≤1000.


Output

The output consists of N rows, each containing the best approximation of the target number using the 5 given numbers.


Sample Input
3
1 2 3 7 100 573
3 26 78 12 17 30
67 69 58 22 2 929


Sample Output
573
30
923

思路：
    似乎完全没方法，提示是回溯
	如何回溯？
	要让这5个数随机组合，组合方式也随机，符号随机
	这个工作量好大

	其实就是树吧，有5个树根
	从其中一个树根出发，有4个子节点，每个子节点有3
	个子子节点，每个子子节点又有2个...
	以此类推，巨大的树，该不会是要构建它吧。

	应该不会，这只是棵抽象树，不一定就是树的数据结构
	可以用递归实现的吧

	基本算法是这样的，先从5棵树根开始，每一树根
	都给它4个子节点，这4个子节点的处理方法和树根
	一样，除非最后一层只有一个子节点，直接返回该子节点

	嗯？数字可以重用麽？似乎不可以，好吧。
	如果用数组实现，那么需要一个flag数组，用于标记哪个
	数字已经被使用掉。

	每递归一次，就消耗一个数（如果是最优，就
	直接返回了

	可能需要递归5层。

	那计算的结果存在哪里呢？
	结果的要求是the best approximation from below of the target number using arithmetic on the 5 given numbers. Note that if it is not possible to reach the exact number, you should give the largest reachable number below the target number.
	尽量与目标值相同，如果达不到，也最好是比目标小的最大值

	这样的话，可能需要保存某条路径上所有的结果，又用一个数组？
	因为是回溯，所以从更深层回来之后，必须修改数组最后一个一个有效值，
	对应着某条路径的最后一个子节点或叶子节点。

	递归体有了，那么边界条件是什么？
	如果是最后一层（第五层），那肯定要回头，
	但不一定用完5个数，所以还有另外的边界条件，
	如果目前计算得到的结果中，已经有值达到了目标值，
	这也要返回。

	那返回的结果是什么？
	最好是目标值，不然也尽可能大，所以这个返回值
	是要实时更新的，每次扩展叶子前，都更新一下返回值
	返回值的范围限定在目标值（最大值）和“现有返回值”之间，
	这样的话，返回值会越递归越大，就算这条路径被回溯了，
	但由它得到的返回值不会受影响，毕竟那个返回值可能是最大的

	所以数据结构是：
	    int number[5] 用户输入的5个数
		bool flag[5] 标记某个数是否被使用
		int result[5]（也就是路径上的所有结果）
	    int target 目标值
		int fakeTarget 已经计算出来的值，它是最终的输出
	函数方法有：
	    DD(int remain) 递归函数，参数表示“仍有多少个数未参与
		               计算”

*/

#include <iostream>
int number[5];
bool flag[5];
int result[5];
int target;
int fakeTarget;

void DD(int remain) {
	
	for (int i = 0; i < remain; i++)
	{
		if (number[i] <= target && number[i] > fakeTarget)
			fakeTarget = number[i];
	}

	if (remain == 1) // 注意：如果remain为0，说明所有数都已经参与运算，只剩下最终结果
		return;
	if (fakeTarget == target)
		return;

	if (remain == 5) // 第一层的初始化
	{
		for (int i = 0; i < 5; i++)
		{
			flag[i] = false;
		}
	}
	
	for (int i = 0; i < remain; i++)
	{
		for (int j = i + 1; j < remain; j++)
		{
			int A = number[i];
			int B = number[j];
			number[j] = number[remain - 1];

			number[i] = A + B;
			DD(remain - 1);
			number[i] = A - B;
			DD(remain - 1);
			number[i] = B - A;
			DD(remain - 1);
			number[i] = A * B;
			DD(remain - 1);

			if (B != 0 && A % B == 0) {
				number[i] = A / B;
				DD(remain - 1);
			}
			if (A != 0 && B % A == 0) {
				number[i] = B / A;
				DD(remain - 1);
			}

			flag[j] = true;

			number[i] = A;
			number[j] = B;
		}
	}
}

int main() {
	int N;
	std::cin >> N;

	while (N--)
	{
		fakeTarget = -999999999;
		for (int i = 0; i < 5; i++)
		{
			std::cin >> number[i];
			flag[i] = false;
			result[i] = 0;
		}
		std::cin >> target;
		DD(5);
		std::cout << fakeTarget << std::endl;
	}
	return 0;
}

/**
我知道了，下面这个递归函数是错误的，因为它每次只和一个数进行运算，
遇到(67-58)*(69+2)这样的式子它就GG了。

void DD(int remain) {
	if (remain == 0) // 注意：如果remain为0，说明所有数都已经参与运算，只剩下最终结果
		return;
	if (fakeTarget == target)
		return;
	for (int i = 0; i < 5; i++)
	{
		if (result[i] <= target && result[i] > fakeTarget)
			fakeTarget = result[i];
	}

	if (remain == 5) // 第一层的初始化
	{
		for (int i = 0; i < 5; i++)
		{
			if (flag[i]) continue;
			flag[i] = true; // 使用该数
			result[0] = number[i];
			DD(remain - 1);
			flag[i] = false;
		}
	}
	else
	{
		for (int j = 0; j < 5; j++)
		{
			if (flag[j]) continue;
			flag[j] = true; // 使用该数

			result[5 - remain] = result[5 - remain - 1] + number[j];
			DD(remain - 1);
			result[5 - remain] = result[5 - remain - 1] - number[j];
			DD(remain - 1);
			result[5 - remain] = number[j] - result[5 - remain - 1];
			DD(remain - 1);
			result[5 - remain] = result[5 - remain - 1] * number[j];
			DD(remain - 1);

			if (number[j] != 0 && result[5 - remain - 1] % number[j] == 0) {
				result[5 - remain] = result[5 - remain - 1] / number[j];
				DD(remain - 1);
			}
			if (result[5 - remain - 1] != 0 && number[j] % result[5 - remain - 1] == 0) {
				result[5 - remain] = number[j] / result[5 - remain - 1];
				DD(remain - 1);
			}

			flag[j] = false;
		}
	}
}

那解决的方法是：每次随机挑选2个数进行运算，而不是将上次结果和随机一个数做运算。
**/

/*******
后记：
    果然是这样。。。
	总算也是过了
	这种随机选两个的算法，我也是看学霸的，确实溜。
	如果我还是留着那个result数组的话，指不定困难度和复杂度都会上升几个数量级
	于是我就妥协了。

	值得注意的是边界
		if (remain == 1) // 注意：如果remain为0，说明所有数都已经参与运算，只剩下最终结果
		return;
		if (fakeTarget == target)
		return;
	放在
		for (int i = 0; i < remain; i++)
		{
			if (number[i] <= target && number[i] > fakeTarget)
				fakeTarget = number[i];
		}
	的后面，因为递归函数的调用是放在计算了路径之后，调用前fakeTarget并没有得到更新
*/