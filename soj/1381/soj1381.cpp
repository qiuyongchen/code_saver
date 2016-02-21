/*

1381. a*b

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description


Give two positive integers a and b, please help us calculate a*b.


Input


The first line of the input is a positive integer T. T is the number of test cases followed.

Each test case contain two integer a,b (0<=a<=10^100, 0<=b<=10,000) given in one line.


Output


The output of each test case should consist of one line, contain the result of a*b.


Sample Input
1
2 7


Sample Output
14

Problem Source

Algorithm Course Examination 2006

思路：
    高精度乘法，其实也就是加法。
	最低位表示做多少次加法，然后小的那个截掉最低位，大的那个增大10倍。
*/

#include <iostream>
#include <string>

// 比较两个字符串的大小
bool bigger(std::string a, std::string b) {
	if (a.length() > b.length() || a.length() == b.length() && a >= b)
	{
		return true;
	}
	return false;
}

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

// 高精度乘法
std::string bigMultiply(std::string a, std::string b) {
	std::string result = "0";

	for (int i = b.length() - 1; i >= 0; i--)
	{
		for (int j = '1'; j <= b[i]; j++)
			result = bigAdd(result, a);

		a = a + '0';
	}

	return result;
}

// 高精度减法(必须保证a > b)
// （老师PPT上的算法似乎是错的...高精度减法也是从最低位算起的）
std::string bigSubstraction(std::string a, std::string b) {
	std::string tempA = a;
	while (a.length() < b.length())
	{
		a = '0' + a;
	}
	while (a.length() > b.length())
	{
		b = '0' + b;
	}

	for (int i = a.length() - 1; i >= 0; i--)
	{
		// 可以直接减掉
		if (a[i] >= b[i]) {
			a[i] = a[i] - b[i] + '0';
		}
		// 必须借位
		else
		{
			a[i - 1] -= 1;
			a[i] = a[i] + 10 - b[i] + '0';
		}
	}

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '0')
		{
			a.erase(0, 1);
			i = -1;
		}
		else
		{
			break;
		}
	}

	if (a.length() == 0)
	{
		a = "0";
	}

	return a;
}

// 高精度除法（必须保证b不为0）
std::string bigDivision(std::string a, std::string b) {
	std::string s, result;

	s = "";
	result = "";

	// 模拟真实除法
	for (int i = 0; i < a.length(); i++)
	{
		s += a[i];
		result += '0';
		while (bigger(s, b))
		{
			result[result.length() - 1] += 1;
			s = bigSubstraction(s, b);
		}
		if (s[0] == '0')
		{
			s.erase(0, 1);
		}
	}

	// 去除结果前边的无用0
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] == '0')
		{
			result.erase(0, 1);
			i = -1;
		}
		else
		{
			break;
		}
	}
	if (result.length() == 0)
	{
		result = "0";
	}

	return result;
}

int main() {
	int testCase = 0;
	std::cin >> testCase;

	std::string a, b, result;
	while (testCase--)
	{
		std::cin >> a >> b;
		std::cout << result << "\n";
	}

	return 0;
}

/*
后记：
    高精度乘法，只要做“各位数值和”那么多次的加法就行了。

	提交的时候，西西里提示我，部分答案错误。

	我仔细检查测试用例，发现问题所在：“0 * 1没有输出”，修改高精度加法后就通过了。
*/