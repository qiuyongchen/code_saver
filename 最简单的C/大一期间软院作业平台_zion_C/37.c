Description:

If you have any doubt on this assignment, please send an email to its author 黄珑.
明明的随机数

Description

明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
Input

 
输入包含多个测试数据。
每个测试数据有2行，第1行为1个正整数，表示所生成的随机数的个数N，第2行有N个用空格隔开的正整数，为所产生的随机数。
 
Output

 
对每个测试数据输出2行。第1行为1个正整数M，表示不相同的随机数的个数。第2行为M个用空格隔开的正整数，为从小到大排好序的不相同的随机数。注意每行最后一个数字后面没有空格。
 
Sample Input

10
20 40 32 67 40 20 89 300 400 15
3
3 2 1
Sample Output

8
15 20 32 40 67 89 300 400
3
1 2 3

Hint:

From soj.me/1341.

Your answer:


#include <stdio.h>
 
int main() {
    int N, M, i, j, temp, min, a[100], b[100];
    char c = 'a';
    scanf("%d", &N);
    do {
        for (i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
 
        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                if (a[j] == a[i]) a[j] = -5;
            }
        }
        for (i = 0, j = 0; i < N; i++) {
            if (a[i] != -5) {
                b[j] = a[i];
                j++;
            }
        }
        M = j;
        for (i = 0; i < M - 1; i++) {
            min = i;
            for (j = i + 1; j < M; j++) {
                if (b[j] < b[min]) {
                    temp = b[j]; b[j] = b[min]; b[min] = temp;
                }
            }
        }
        printf("%d\n", M);
        for (i = 0; i < M; i++) {
            printf("%d", b[i]);
            if (i != M -1) printf(" ");
        }
        printf("\n");
    } while (scanf("%d", &N) != EOF);
    return 0;
}
