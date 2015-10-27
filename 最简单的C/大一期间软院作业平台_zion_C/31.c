Good:

So bad

Description:

If you have any doubt on this assignment, please send an email to its author 范子垚.
Talent Chan is a box master. He has a very large box to contain his collections, but the box can only contain totally v weight of things. He also has n objects with different weights and values. So maybe he cannot put all the collections in the box. Now you are learning box skills from Talent Chan, so your task is to write a program to decide how to put things into the box that the sum of thing' values in the box is the most.
input data : first line 2 integers v(0<=v<=5000) and n(0<=n<=50). next n line have 2 integer wi and vi.
output data : one integer, the max sum of values.
sample input:
10 3
3 4
4 5
5 6
sample output:
11
中文题面： 
陈天才是个装箱大师，他有一个箱子容量（可装物品的最大重量总和）为v(正整数，o≤v≤5000)，同时有n个物品(o≤n≤50)每个物品有一个重量和价值 (正整数)。现在你是他的学徒，你要写个程序，计算从 n 个物品中，任取若千个装入箱内，使箱内的物品的总价值最大。
备注：不要以为wi是worth，vi是volumn，好好看题目- -

Hint:

可以用递归也可以设法递推。
​

#include <stdio.h>
int a[51][5001];


int most(int vv, int n) {
    int i, j, w[51], v[51];
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    for (i = 0; i < 51; i++) {
        for (j = 0; j < 5001; j++) {
            a[i][j] = 0;
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= vv; j++) {
            if (j >= w[i]) {
                if ((v[i] + a[i - 1][j - w[i]]) > a[i - 1][j]) {
                    a[i][j] = (v[i] + a[i - 1][j - w[i]]);
                } else {
                    a[i][j] = a[i - 1][j];
                }
            } else {
                a[i][j] = a[i - 1][j];
            }
        }
    }
    return a[n][vv];
}


int main() {
    int v, n, x;
    scanf("%d%d", &v, &n);
    x = most(v, n);
    printf("%d\n", x);
    return 0;
}



standard:
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
 
int i, j, m, n, v[100], w[100], f[5001] = {0};
 
int main() {
    scanf("%d%d", &m, &n);
    for (i = 0; i < n; ++i)
        scanf("%d%d", &w[i], &v[i]);
    for (i = 0; i < n; ++i)
    for (j = m; j >= w[i]; --j)
            f[j] = max(f[j-w[i]] + v[i], f[j]);
    printf("%d\n", f[m]);
    return 0;
}
