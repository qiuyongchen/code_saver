Description:

If you have any doubt on this assignment, please send an email to its author 黄珑.
Description
有一天, PY找到了一张藏宝图. 这张地图被划分成 2^n * 2^n 个格子.左上角的格子的坐标为 (0, 0) 而右下角格子的坐标为 (2^n-1, 2^n-1). 如下:
 
(0, 0)
(0, 1)
……
(0, 2^n-1)
……
……
……
……
(2^n-2, 0)
(2^n-2,1)
……
(2^n-2, 2^n-1)
(2^n-1, 0)
(2^n-1,1)
……
(2^n-1, 2^n-1)
 
幸运地他发现了一条密文, 这是一条长度为N的序列, 旁边的注释说道: 
           "重复这些动作N次你就会找到宝藏:
1、将地图分成 四个2^(n-1) * 2^(n-1) 的部分:左上角的部分编号为 0, 右上角的部分编号为1, 左下角的部分编号为 2 , 而右下角的部分编号为3
                2、按照序列的第一个数字来选择你要继续搜寻的部分.
                3、删去序列的第一个数字
                4、将N减去1
          最后你将到达宝藏的所在"
        
我们怎能忍心让PY继续做卢瑟? 这就是他命运的转折点, 让我们助他成为高富帅.
Input
输入的第一行是一个整数T, 代表输入数据的组数.
对于每组数据,这里只有一行, 包括一个整数N(1<=n<=31)和一个长度为N的序列 (这个序列只包括‘0’, ‘1’, ‘2’ , ’3’).
Output
对于每组数据, 输出X和Y, 即宝藏所在地的坐标.
 
Sample Input
 Copy sample input to clipboard
3
1 3
2 00
2 01
Sample Output
1 1
0 0
0 1

Hint:

From soj某比赛。

Your answer:


/* Money of Py*/
#include <stdio.h>
#include <math.h>


/*function main begins program execution*/
int main() {
    int x = 0, y = 0, i, j, n, a[31], t, k;
    scanf("%d", &t);
    for (k = 0; k < t; k++) {
        x = 0;
        y = 0;
        scanf("%d", &n);
        j = n;
        for (i = 0; i <= n; i++) {
            a[i] = getchar();
        }
        for (i = 1; i <= j; i++) {
            if (a[i] == '0') {
            } else if (a[i] == '1') {
                y = y + pow(2, n - 1);
            } else if (a[i] == '2') {
                x = x + pow(2, n - 1);
            } else if (a[i] == '3') {
                x = x + pow(2, n - 1);
                y = y + pow(2, n - 1);
            }
            n--;
        }
        printf("%d %d\n", x, y);
    }
    return 0;
} /*end function main*/

