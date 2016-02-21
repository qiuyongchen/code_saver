/*

1063. Who's the Boss

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

Several surveys indicate that the taller you are, the higher you can climb the corporate ladder. At TALL Enterprises Inc. this "de facto standard" has been properly formalized: your boss is always at least as tall as you are. Furthermore, you can safely assume that your boss earns a bit more than you do. In fact, you can be absolutely sure that your immediate boss is the person who earns the least among all the employees that earn more than you and are at least as tall as you are. Furthermore, if you are the immediate boss of someone, that person is your subordinate, and all his subordinates are your subordinates as well. If you are nobody's boss, then you have no subordinates. As simple as these rules are, many people working for TALL are unsure of to whom they should be turning in their weekly progress report and how many subordinates they have. Write a program that will help in determining for any employee who the immediate boss of that employee is and how many subordinates they have. Quality Assurance at TALL have devised a series of tests to ensure that your program is correct. These test are described below.


Input


On the first line of the input is a single positive integer n, telling the number of test scenarios to follow. Each scenario begins with a line containing two positive integers m and q, where m (at most 30000) is the number of employees and q (at most 200) is the number of queries. The following m lines each list an employee by three integers on the same line: employee ID number (six decimal digits, the first one of which is not zero), yearly salary in Euros and finally height in m (1 microm= 10^-6 meters - accuracy is important at TALL). The chairperson is the employee that earns more than anyone else and is also the tallest person in the company. Then there are q lines listing queries. Each query is a single legal employee ID.

The salary is a positive integer which is at most 10 000 000. No two employees have the same ID, and no two employees have the same salary. The height of an employee is at least 1 000 000 microm and at most 2 500 000 microm.


Output

For each employee ID x in a query output a single line with two integers y k, separated by one space character, where y is the ID of x's boss, and k is the number of subordinates of x. If the query is the ID of the chairperson, then you should output 0 as the ID of his or her boss (since the chairperson has no immediate boss except, possibly, God).


Sample Input
2
3 3
123456 14323 1700000
123458 41412 1900000
123457 15221 1800000
123456
123458
123457
4 4
200002 12234 1832001
200003 15002 1745201
200004 18745 1883410
200001 24834 1921313
200004
200002
200003
200001


Sample Output
123457 0
0 2
123458 1
200001 2
200004 0
200004 0
0 3

思路：
题目大概的意思是说，给出好多个ID，每个ID有属性
查询某个ID，输出排在它前面的ID和它后面的ID数量
这，似乎用个排序就可以了。

数据结构用map好了
*/

/*
#include <iostream>
#include <map>

int main() {
int N; // 测试用例数量
std::cin >> N;

int emploee, query;

int ID, salary, height;

std::map<int, int> person; // 存放所有ID、ID的薪水
std::map<int, int>::iterator it;
std::map<int, int>::iterator it_next;

while (N--)
{

std::cin >> emploee >> query;
for (int i = 0; i < emploee; i++)
{
std::cin >> ID >> salary >> height;
person.insert(std::make_pair(salary, ID));
}
for (int i = 0; i < query; i++)
{
std::cin >> ID;
int j = 0;
// 遍历以寻找到ID（map已经升序有序）
for (it = person.begin(); it != person.end(); it++)
{
if ((*it).second != ID)
{
j++;
continue;
}
else
{
it_next = it;
it_next++;
if (it_next != person.end())
{
std::cout << (*it_next).second;
}
else
{
std::cout << "0";
}
std::cout << " " << j << std::endl;
break;
}
}
}
person.clear();
}
return 0;
}
*/

#include <stdio.h>
#include <iostream>

struct E
{
	int ID;
	int salary;
	int height;
	int subordinates;
}P[30001];

E t;
E pEnd;

int boss[30001];

int isBoss(E boss, E emploee) {
	return (boss.salary > emploee.salary) && (boss.height >= emploee.height);
}

int QSORT_action(E *p, int begin, int end) {

	int i = begin - 1;

	int j = begin;

	for (; j <= end - 1; j++)
	{
		if (p[j].salary >= p[end].salary) {
			i++;
			t = p[j];
			p[j] = p[i];
			p[i] = t;
		}
	}

	t = p[end];
	p[end] = p[i + 1];
	p[i + 1] = t;

	return i + 1;

}

void QSORT(E *p, int begin, int end) {
	if (begin < end)
	{
		int temp = QSORT_action(p, begin, end);
		QSORT(p, begin, temp - 1);
		QSORT(p, temp + 1, end);
	}
}

int main() {
	int N;

	int emploee, query;

	int ID, salary, height;
	int i, j;

	std::cin >> N;

	while (N--)
	{
		/* 数组待初始化*/
		/*      for (int i = 0; i < 30005; i++)
		{
		boss[i] = 0;

		P[i].height = 0;
		P[i].ID = 0;
		P[i].salary = 0;
		P[i].subordinates = 0;
		}*/

		std::cin >> emploee >> query;

		for (i = 0; i < emploee; i++)
		{
			std::cin >> P[i].ID >> P[i].salary >> P[i].height;
			P[i].subordinates = 0;
			boss[i] = -1;
		}

		QSORT(P, 0, emploee - 1);

		for (i = emploee - 1; i >= 0; i--)
		{
			for (j = i - 1; j >= 0; j--) {
				if (P[j].height >= P[i].height) // 保持最简的判断，多一个“于”就可能超时
				{
					boss[i] = j; /* 确定每个员工的顶头BOSS*/
					P[j].subordinates += (P[i].subordinates + 1); /* 该顶头BOSS的下属数量
																  //（由最底层往上遍历，所
																  // 以一旦确定了某个BOSS的下属数，该BOSS的下属不会再变大）*/
					break;
				}
			}

		}
		for (i = 0; i < query; i++)
		{
			std::cin >> ID;

			for (j = 0; j < emploee; j++)
			{
				if (P[j].ID == ID)
				{
					std::cout << ((boss[j] == -1) ? 0 : P[boss[j]].ID) << " " << P[j].subordinates << std::endl;
					break;
				}
			}

		}
	}
	return 0;
}
/*
后记：
我似乎弄错了一些东西，
只有薪水和身高都比较大的才是boss，不然不是
这样的话，我就错得很严重，必须亲自写个排序了
顺便也复习一下快排

20 10
19 9
10 20
9 10
8  8
7 15

我知道为什么一直会wrong answer了

把别人的下属划分到自己的名下！！

倒是排好序了 但是，超时。。。

这，让我情何以堪？

去掉排序，这答案错误，这排序真的那么费时？

accept之后，我激动得感谢耶稣。这玩意，又有经验得到：
1.绝不要用C语言了，很麻烦，命名麻烦，很多要求，其实不是说struct一定要初始化
之前出错的原因可能是上下文的关系。
2.if要保持最简的判断，多一个“于”就可能超时
*/