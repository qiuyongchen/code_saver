#include <iostream>
#include <string>

/*******************************************************
Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

Mo and Larry have devised a way of encrypting messages. They first decide secretly on the number of columns and write the message (letters only) down the columns, padding with extra random letters so as to make a rectangular array of letters. For example, if the message is "There's no place like home on a snowy night" and there are five columns, Mo would write down t o i o y h p k n n e l e a i r a h s g e c o n h s e m o t n l e w x Note that Mo includes only letters and writes them all in lower case. In this example, Mo used the character `x' to pad the message out to make a rectangle, although he could have used any letter. Mo then sends the message to Larry by writing the letters in each row, alternating left-to-right and right-to-left. So, the above would be encrypted as toioynnkpheleaigshareconhtomesnlewx Your job is to recover for Larry the original message (along with any extra padding letters) from the encrypted one.


Input

There will be multiple input sets. Input for each set will consist of two lines. The first line will contain an integer in the range 2 . ..20 indicating the number of columns used. The next line is a string of up to 200 lower case letters. The last input set is followed by a line containing a single 0, indicating end of input.


Output

Each input set should generate one line of output, giving the original plaintext message, with no spaces.


Sample Input
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
0


Sample Output
theresnoplacelikehomeonasnowynightx
thisistheeasyoneab

思路：
  我画了一个长方形图，觉得还是很好解的。
  一开始指定的column就决定了长方形的一边，剩下的一边就用总长度除掉已知边得到
  解密的时候，从0到总长度，逐个取
  具体是怎么取呢？
  一列一列地取话，列下标从0到column，针对每一列，都取完相应行。
  这样下来，差不多就可以了吧。

********************************************************/
int main() {
	int N;
	int row;
	std::string str = "";
	char a[200][20] = { 0 };

	std::cin >> N;
	while (N != 0)
	{
		std::cin >> str;
		row = str.length() / N;
		for (int i = 0; i < str.length(); i++)
		{
			// 偶数行，顺序存储
			if ((i / N) % 2 == 0)
			{
				a[i / N][i % N] = str[i];
			}
			// 奇数行， 反序存储（注意列数N必须减1）
			else
			{
				a[i / N][N - 1 - i % N] = str[i];
			}
		}
		
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < row; i++)
			{
				std::cout << a[i][j];
			}
		}
		
		std::cout << "\n";

		std::cin >> N;
	}
	return 0;
}

/********************************************************************
    后记：
	    这次我犯了个大错误，我把二维数组当做一维数组输出了...
		结果，不管我怎么调试，每次想输出a[i * N + j]时，都莫名其妙输出一整行，
		后来才发现a是二维数组，a[i * N + j]真的是输出一整行的。
		唉，太笨了。
*********************************************************************/