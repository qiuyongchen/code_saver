/************************************************************************************

1006. Team Rankings

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

It's preseason and the local newspaper wants to publish a preseason ranking of the teams in the local amateur basketball league. The teams are the Ants, the Buckets, the Cats, the Dribblers, and the Elephants. When Scoop McGee, sports editor of the paper, gets the rankings from the selected local experts down at the hardware store, he's dismayed to find that there doesn't appear to be total agreement and so he's wondering what ranking to publish that would most accurately reflect the rankings he got from the experts. He’s found that finding the median ranking from among all possible rankings is one way to go.

The median ranking is computed as follows: Given any two rankings, for instance ACDBE and ABCDE, the distance between the two rankings is defined as the total number of pairs of teams that are given different relative orderings. In our example, the pair B, C is given a different ordering by the two rankings. (The first ranking has C above B while the second ranking has the opposite.) The only other pair that the two rankings disagree on is B, D; thus, the distance between these two rankings is 2. The median ranking of a set of rankings is that ranking whose sum of distances to all the given rankings is minimal. (Note we could have more than one median ranking.) The median ranking may or may not be one of the given rankings.

Suppose there are 4 voters that have given the rankings: ABDCE, BACDE, ABCED and ACBDE. Consider two candidate median rankings ABCDE and CDEAB. The sum of distances from the ranking ABCDE to the four voted rankings is 1 + 1 + 1 + 1 = 4. We'll call this sum the value of the ranking ABCDE. The value of the ranking CDEAB is 7 + 7 + 7 + 5 = 26.

It turns out that ABCDE is in fact the median ranking with a value of 4.


Input

There will be multiple input sets. Input for each set is a positive integer n on a line by itself, followed by n lines (n no more than 100), each containing a permutation of the letters A, B, C, D and E, left-justified with no spaces. The final input set is followed by a line containing a 0, indicating end of input.


Output

Output for each input set should be one line of the form:

ranking is the median ranking with value value.

Of course ranking should be replaced by the correct ranking and value with the correct value. If there is more than one median ranking, you should output the one which comes first alphabetically.


Sample Input
4
ABDCE
BACDE
ABCED
ACBDE
0


Sample Output
ABCDE is the median ranking with value 4.

思路：
	 这道题咋一看挺麻烦的，让我梳理一下思路
	 首先输入的是一大堆长度为5仅有ABCDE5个字母的字符串
	 我们要从中找出median ranking
	 为了找出这median ranking，我们必须求每个字符串的rank sum
	 为了求rank sum，必须两两字符串逐个比较

	 但，but,这和栈有什么关系？还回溯了都，搞不明白。

	 我查了一下大牛的思路，发现他们都是用全排列？这是为什么，不是只要和输入的字符串相比就行了麽？
	 为什么要大花功夫去和全排列比呢？难道是“XP系统”？

	 再说，如果和全排列相比，势必会和某...等等，好像我理解错了

	 似乎题目给出的几个字符串不一定就是最终答案
	 whose sum of distances to all the given rankings....
	 The median ranking may or may not be one of the given rankings.

	 这样的话，倒是必须用全排列了，如果答案不一定是给出的字符串里某一个的话。

	 首先有全排列（5！个），全排列中所有的字符串都等待着输入的字符串，
	 一旦用户输入了一条字符串，全排列中所有的字符串都与用户字符串作比较，
	 如果用户不再输入了，那么看看全排列中所有的字符串，谁的sum最小，就是谁。

	 应该就是这么一回事儿了。

	 问题来了，全排列怎么生成？用5个for循环直接生成？这样就5的5次方了，不对，字母不重复，顶多就是5！而已。
	 莫非真的要用5个嵌套的循环？太那个了，丑！

	 如果用栈该怎么搞？
	 算了，不要栈了，直接嵌套循环得了，似乎栈挺麻烦的。
	 那么就这样，弄个flag[5]出来，flag[0]代表A，flag[1]代表B，如果for循环里已经用了某个字母就不用再去循环它了。

	 首先构建全排列，让用户无脑输入所有的字符串，然后再遍历所有全排列（全排列中的每一字符串都与所有的用户字符串搞小动作）
	 然后评选“小动作之王”！

*************************************************************************************/

#include <iostream>
#include <string>

std::string onlooker[120]; // 存放全排列（5!）

// 无脑生成从A到E的全排列
void permutation() {
	bool flag[5] = { false };
	int count = 0;
	std::string c = "ABCDE";

	for (int i = 'A'; i < 'F'; i++)
	{
		flag[i - 'A'] = true;

		for (int j = 'A'; j < 'F'; j++)
		{
			if (flag[j - 'A'])
			{
				continue;
			}
			flag[j - 'A'] = true;

			for (int k = 'A'; k < 'F'; k++)
			{
				if (flag[k - 'A'])
				{
					continue;
				}
				flag[k - 'A'] = true;

				for (int l = 'A'; l < 'F'; l++)
				{
					if (flag[l - 'A'])
					{
						continue;
					}
					flag[l - 'A'] = true;

					for (int m = 'A'; m < 'F'; m++)
					{
						if (flag[m - 'A'])
						{
							continue;
						}
						flag[m - 'A'] = true;
						c[0] = i;
						c[1] = j;
						c[2] = k;
						c[3] = l;
						c[4] = m;
						onlooker[count++] = c;
						flag[m - 'A'] = false;

					}

					flag[l - 'A'] = false;
				}

				flag[k - 'A'] = false;
			}

			flag[j - 'A'] = false;
		}

		flag[i - 'A'] = false;
	}
}

// 计算两个字符串之间的difference
int difference(std::string A, std::string B) {
	int n = 0;

	// B[i]的位置 是B[j]的前面的，如果B[i]代表的字母在A中是靠后的，那明显是different的了
	for (int i = 0; i < A.length() - 1; i++)
	{
		for (int j = i + 1; j < A.length(); j++)
		{
			if (A.find(B[i]) > A.find(B[j]))
			{
				n++;
			}
		}
	}

	return n;
}

int main() {
	permutation();

	// 用户输入的字符串
	std::string participator;
	// 参与排行的队伍数量
	int N;

	std::cin >> N;

	while (N != 0)
	{
		int sum[120] = { 0 };
		int theChosenOne = 0;

		for (int i = 0; i < N; i++)
		{
			std::cin >> participator;
			for (int j = 0; j < 120; j++)
			{
				sum[j] += difference(onlooker[j], participator); // 全排列的sum
			}
		}

		for (int j = 0; j < 120; j++)
		{
			if (sum[j] < sum[theChosenOne])
				theChosenOne = j;
		}

		std::cout << onlooker[theChosenOne] << " is the median ranking with value " << sum[theChosenOne] << ".\n";
		std::cin >> N;
	}


	return 0;
}

/**********************************************************
后记：
    居然利用睡前时间做了一道题。。。。
	这题还是比较简单的，但我也二了一回，
	写那个difference函数的时候，我判断字符串中的字符位置时，前后弄混了。。。。。
	if (A.find(B[i]) > A.find(B[j]))
	写成
	if (A.find(B[i]) < A.find(B[j]))

	郭老头说这个题是用来练习栈的，结果，哎，我还是用笨方法吧。
***********************************************************/
