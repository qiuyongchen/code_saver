/*

1029. Rabbit

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description


The rabbits have powerful reproduction ability. One pair of adult rabbits can give birth to one pair of 
kid rabbits every month. And after m months, the kid rabbits can become adult rabbits.
As we all know, when m=2, the sequence of the number of pairs of rabbits in each month is called 
Fibonacci sequence. But when m<>2, the problem seems not so simple. You job is to calculate after d 
months, how many pairs of the rabbits are there if there is exactly one pair of adult rabbits initially. 
You may assume that none of the rabbits dies in this period.

Input

The input may have multiple test cases. In each test case, there is one line having two integers m
(1<=m<=10), d(1<=d<=100), m is the number of months after which kid rabbits can become adult rabbits, 
and d is the number of months after which you should calculate the number of pairs of rabbits. 
The input will be terminated by m=d=0.

Output

You must print the number of pairs of rabbits after d months, one integer per line.

Sample Input
2 3
3 5
1 100
0 0


Sample Output
5
9
1267650600228229401496703205376

Problem Source

ZSUACM Team Member

思路：
    兔子生兔子，难道老兔子不会死么？
	先逐月求出成年的兔子，再加上未成年的崽崽。（当月有多少成年兔，就有多少崽崽被生出来。）

	但是考虑到兔子有大量的崽崽，恐怕是要用高精度加法咯，正好可以学习一下高精度加法。
*/

#include <iostream>
#include <string>

// 高精度加法
std::string bigAdd(std::string a, std::string b) {
	while (a.length() < b.length())
	{
		a = '0' + a;
	}
	while (a.length() > b.length())
	{
		b = '0' + b;
	}

	std::string sum = '0' + a;
	for (int i = 0; i < sum.length(); i++)
	{
		sum[i] = '0';
	}

	for (int i = a.length() - 1; i >= 0; i--)
	{
		sum[i + 1] += a[i] - '0' + b[i] - '0';
		if (sum[i + 1] > '9')
		{
			sum[i + 1] -= 10;
			sum[i] += 1;
		}
	}

	for (int i = 0; i < sum.length(); i++)
	{
		if (sum[i] == '0')
		{
			sum.erase(0, 1);
			i = -1;
		}
		else
		{
			break;
		}
	}

	if (sum.length() == 0)
	{
		sum = "0";
	}
	return sum;
}

int main() {
	int m, d;
	std::string sum;
	std::string a[102];
	while (std::cin >> m >> d && m != 0 && d != 0)
	{
		a[1] = "1";
		for (int i = 2; i <= d; i++)
		{
			a[i] = (i > m) ? bigAdd(a[i - m], a[i - 1]) : a[i - 1];
		}
		sum = a[d];

		// 如果m比d大了很多很多
		int i = d - m + 1;
		if (i < 1)
		{
			i = 1;
		}

		for (i; i <= d; i++)
		{
			sum = bigAdd(sum, a[i]);
		}

		std::cout << sum << "\n";
	}

	return 0;
}

/*
后记：
    高精度加法，还算简单。
	提交的时候遇到了Runtime Error，我一愣，心想：“难道是数组太大了？”
	于是静悄悄地把数组大小改小一些，遗憾的是问题依旧在。

	想来想去，在VS2015上代码可以正常运行，西西里却没法运行我的代码？
	莫非是西西里版本落后太多，对某些官方函数不支持？
	我找来找去，也没找到什么特别的函数。

	最后我才想起，可能是某些测试用例导致了越界！
	我令m = 10，令d = 1，果然有问题，稍作修改，顺利accept。

	西西里上边的错误有时挺烦人的
*/