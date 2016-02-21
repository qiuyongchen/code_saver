/* *

1198. Substring
Constraints

Time Limit: 1 secs, Memory Limit: 32 MB
Description

Dr lee cuts a string S into N pieces,s[1],…,s[N].   

Now, Dr lee gives you these N sub-strings: s[1],…s[N]. There might be several possibilities that the string S could be. For example, if Dr. lee gives you three sub-strings {“a”,“ab”,”ac”}, the string S could be “aabac”,”aacab”,”abaac”,…   

Your task is to output the lexicographically smallest S. 

Input

        The first line of the input is a positive integer T. T is the number of the test cases followed.   

The first line of each test case is a positive integer N (1 <=N<= 8 ) which represents the number of sub-strings. After that, N lines followed. The i-th line is the i-th sub-string s[i]. Assume that the length of each sub-string is positive and less than 100. 

Output

The output of each test is the lexicographically smallest S. No redundant spaces are needed. 

Sample Input

1
3
a
ab
ac

Sample Output

aabac

Problem Source

ZSUACM Team Member

思路：
    这题有点意思，构建字典序最小的字符串。
	看来还是那一套方法，全部存入set，根据set的自动排序原则，直接输出算了。
	
	现在第一版代码写出来，还没运行，我突然想到，如果子窜如果相同怎么办，set里面是不能有相同的元素的。
	
	果然，wrong answer.
	
	那么，似乎multiset可以容许相同元素？让我查查。
	
	也不行，"ba"和"b"有问题，排序默认是b而不是ba在前面
	
	算了，似乎是贪心算法？
	
	我直接排序算了，人工排序。

* */
/* *
#include <iostream>
#include <set>
#include <string>

int main()
{
	int T;
	int N;
	std::multiset<std::string> substring;
	std::string sub, str;
	std::cin >> T;
	
	while (T--)
	{
		std::cin >> N;
		while (N--)
		{
			std::cin >> sub;
			substring.insert(sub);
		}
		for (std::multiset<std::string>::iterator it = substring.begin(); it != substring.end(); it++)
		{
			std::cout << *it;
		}
		std::cout << "\n";
	}
	return 0;
}
* */

#include <algorithm>
#include <iostream>
#include <string>

bool cmp(std::string str_a, std::string str_b)
{
	return str_a + str_b < str_b + str_a;
}

int main()
{
	int T, N;
	std::string str[10];
	std::cin >> T;
	
	while (T--)
	{
		std::cin >> N;
		for (int i= 0; i < N; i++)
		{
			str[i].resize(101);
			std::cin >> str[i];
		}
		
		sort(str, str + N, cmp);
		
		for (int i= 0; i < N; i++)
		{
			std::cout << str[i];
		}
		std::cout << "\n";
	}
	return 0;
}

/* *
后记：
    直接来比较残暴，这次倒是复习了algorithm中sort的用法--->把分别对应数组头和数组尾的两个指针传进去，再传一个比较大小的函数，即可。
	再者就是string的resize函数，长度不够会补全，长度太长会切短。
	最后是string的比较运算符，我猜是字典序。
* */