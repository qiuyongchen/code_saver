/*
Constraints

Time Limit: 10 secs, Memory Limit: 32 MB

Description

歌手The Pancakes到幼儿园跟小朋友玩耍，她到达的时候小朋友们已经争着积木玩了。小朋友都想要更多的积木砌一个自己喜欢的图形，
砌完就可以和The Pancakes合照。同时，The Pancakes手上还有一些积木，她可以把手上的这些积木全部给一个小朋友，
然后等该小朋友砌完后就可以收回所发的积木和该小朋友原先手上的积木。但她不知道能否让所有的小朋友都和她合照，
聪明的你可以帮助她吗？

Input


输入包含多个数据。

每个数据的第一行是两个正整数n和s，1≤n≤10000，1≤s≤1000000，表示一共有n位小朋友，The Pancakes手上有s块积木。
以下有n行，每行有两个正整数，a和b，1≤a，b≤10^9，表示第i个小朋友手上有a块积木，还需要b块积木才能够砌完。

输入n=0时表示结束。


Output

如果可以让所有小朋友都和Pancake合照，就输出YES；否则，输出NO。

Sample Input
2 2
1 4
2 1
2 2
1 4
1 1
0 0

Sample Output
YES
NO

Problem Source

ZSUACM Team Member

思路：
    歌手手中的积木估计很少，她首先可以跟那些需求少的孩子合作，把孩子的积木骗过来
	之后，她手中的积木变多，可以和需求多的孩子合作...
*/

#include <iostream>
#include <vector>
#include <algorithm>



class KIDS
{
public:
	KIDS(int a, int b) { handed = a; need = b; }
	int handed;
	int need;
};

bool kidsCMP(KIDS a, KIDS b) {
	return a.need < b.need;
}

int main() {
	int num_kid, s;
	int a, b;
	std::vector<KIDS> kids;

	std::cin >> num_kid >> s;

	while (num_kid != 0) {
		while (num_kid--) {
			std::cin >> a >> b;
			kids.push_back(KIDS(a, b));
		}

		sort(kids.begin(), kids.end(), kidsCMP);

		int i = 0;
		while (i < kids.size() && s >= kids[i].need)
		{
			s += kids[i].handed;
			i++;
		}

		if (i == kids.size())
		{
			std::cout << "YES\n";
		}
		else
		{
			std::cout << "NO\n";
		}

		kids.clear();
		std::cin >> num_kid >> s;
	}
	
	return 0;
}

/*
后记：
    这题里复习了公用算法sort，传入容器的头iterator、尾iterator和比较算法即可。
*/