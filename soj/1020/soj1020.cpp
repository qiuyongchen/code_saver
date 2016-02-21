/** *
大数的求模算法
解题的思路只需要三条公式：
  (A + B) % N = (A % N + B % N) % N
  (A - B) % N = (A % N - B % N) % N
  (A * B) % N = (A % N * B % N) % N 
也就是说，如果一个大数由2个数结合而来，那么先把2个数求模，然后再结合起来，搞定。
依据这三条公式，具体的算法便是可以运用老爷子说的“递归策略”：
  如，
  85745 % 6 = （（8 % 6 × 10000） + 5745
  ...
  ..
  .
这个思路，实际上，和我们小学学到的做除法，根本没区别嘛。
先对最高位求模，得到的结果与次高位结合，继续求模，不断地递归下去，结果就出来了，时间复杂度估计是O(N)。
核心公式：i from 0 to length, r = (r * 10 + a[i]) % m


1020. Big Integer


Constraints
Time Limit: 1 secs, Memory Limit: 32 MB


Description

Long long ago, there was a super computer that could deal with VeryLongIntegers(no VeryLongInteger will be negative). Do you know how this computer stores the VeryLongIntegers? This computer has a set of n positive integers: b1,b2,...,bn, which is called a basis for the computer.

The basis satisfies two properties:
1) 1 < bi <= 1000 (1 <= i <= n),
2) gcd(bi,bj) = 1 (1 <= i,j <= n, i ≠ j).

Let M = b1*b2*...*bn

Given an integer x, which is nonegative and less than M, the ordered n-tuples (x mod b1, x mod b2, ..., x mod bn), which is called the representation of x, will be put into the computer.


Input

The input consists of T test cases. The number of test cases (T) is given in the first line of the input.
Each test case contains three lines.
The first line contains an integer n(<=100).
The second line contains n integers: b1,b2,...,bn, which is the basis of the computer.
The third line contains a single VeryLongInteger x.

Each VeryLongInteger will be 400 or fewer characters in length, and will only contain digits (no VeryLongInteger will be negative).


Output

For each test case, print exactly one line -- the representation of x.
The output format is:(r1,r2,...,rn)


Sample Input

2

3
2 3 5
10

4
2 3 5 7
13


Sample Output

(0,1,0)
(1,1,3,6)

Problem Source

ZSUACM Team Member
* */

#include <iostream>
#include <string>

using namespace std;

/** *
求大数模的函数，模仿小学生算法
* */
int getMod(string VeryLongInteger, int n)
{
	int r = 0;
	for (int i = 0; i < VeryLongInteger.length(); i++)
	{
		r = (r * 10 + VeryLongInteger[i] - '0') % n;
	}
	return r;
}

int main()
{
	int array_in[100];
	string VeryLongInteger;

	int test_cases = 0;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++)
	{
		int n;
		cin >> n;
		
		for (int j = 0; j < n; j++)
		{
			cin >> array_in[j];
		}
		
		cin >> VeryLongInteger;
		
		cout << "(";
		
		for (int j = 0; j < n; j++)
		{
			cout << getMod(VeryLongInteger, array_in[j]);
			if (j != n - 1)
			{
				cout << ",";
			}
		}
		
		cout << ")\n";
	}
	return 0;
}


/** *
哎呀，居然一次就过了，这，还怎么玩？
过了一道，我看了看，要想刷到第一版，恐怕得要360道题。
算了，七七四十九，我直接刷到490道，正好每周70道，平均下来每天10道...
** */