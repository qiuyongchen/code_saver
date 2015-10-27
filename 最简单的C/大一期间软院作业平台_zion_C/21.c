Good:

递推式&&use another arrey to store data to save time and memory.
Description:

Uncle Long once stands in the top of a number pyramid. As you know, its shape is like triangle. He would walk down back to ground. Fortunately, once he goes over a number, he will get the same amount money of the number.
The rules are:
1 He can only go down, never goes up or goes back  or the same floor.
2 He can only go left down or right down near to it, like the pic below: 2 can only goes to 4 or 5, 5 can only goes to 8 or 9.
     1
    2 3
  4 5 6
7 8 9 10
Uncle Long dreams to get the most money he might get during walking, but he was too foolish to decide the route. So he ask you to solve it. If you don't tell him, he would make you failed at programming. 233
So your task is to output the maxinum money Uncle Long can get in the given pyramid.
input data: 
first line only one integer n (3<n<=500), the next n lines, every ith line has i numbers(not greater than 999), to show you the pyramid.
output data:
only one integer, the maxinum answer of the pyramid.
4
33
22 44
14 25 15
91 73 26 82
example output:
175
 
中文题面：
Uncle Long站在一个数字金字塔顶，你可以将其看作一个等边三角形。他将要从顶上往下走回地面，不过幸运的是，每走过一个格子，他都会得到与格子上写着数字相等分量的金钱。但是下塔是有路线规则的。
1 他只能往下走，不能往上、回头或者平着往左右走。
2 他只能往左下或者右下最接近的格子走，比如说下图中：2处只能走向4或5，5处只能走向8或9.
     1
    2 3
  4 5 6
7 8 9 10
你们懂的，Uncle Long比较贪心，他想要得到可能得到的最大数量金钱，但是他财迷心窍以至于智商下降，没法决定路线！所以他以TA的权限要挟你帮他找出最佳路线，否则就会被挂科！233
你不想挂课，所以要帮他找出最佳路线，你只用输出最佳路线能得多少钱。
输入数据：第一行一个整数n(3<n<=500)，接下来的n行，每第i行都有i个不超过999的整数，是当前格子的数字，他们组成了这个数字金字塔。
输出数据：一个整数，就是最佳路线的金钱收益。
样例输入：
4
33
22 44
14 25 15
91 73 26 82
样例输出：
175
Note: If you have any question on the description, please send an email to its author.

Hint:

设法推出每个位置的最优解，和推出下一个位置最佳解的递推式，从而得到全局最优解。自顶向下和自下向顶都可以的。






#include <stdio.h>

int a[500][500];
int m[500][500];
int Num;

int max(int a, int b) {
    return a > b ? a : b;
}
int Func(int i, int j) {
    if (m[i][j] != 0) {
        return m[i][j];
    } else {
        if (i == Num - 1) {
            m[i][j] = (max(a[i + 1][j], a[i + 1][j +1])) + a[i][j];
            return m[i][j];
        } else {
            m[i][j] = (max(Func(i+1, j), Func(i +1, j+1))) + a[i][j];
            return m[i][j];
        }
    }
}

int main() {
    int i, j;
    scanf("%d", &Num);
    for (i = 1; i <= Num; i++) {
        for (j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
            m[i][j] = 0;
        }
    }
    printf("%d\n", Func(1, 1));
    return 0;
}

