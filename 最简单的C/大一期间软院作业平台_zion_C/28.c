Good：

翻转数组。

Description:

If you have any doubt on this assignment, please send an email to its author 林培泳.
 Give a sequence contains N numbers a1,a2...aN. We have M operators ,each operator has two number L,R, reverse the numbers between a[L] and a[R] in sequence.
The  first line contains two integers N,M. (1<=N,M<=1000)
The second line describe N numbers in sequence.
The Next M lines,each line has two integers L,R (1<=L<=R<=N)
Output single line describe the sequence after all operators. There is one space between two numbers.
  [Input]
10 2
1 2 3 4 5 6 7 8 9 10
2 4
6 9
[Output]
1 4 3 2 5 9 8 7 6 10


Hint:

#include <stdio.h>
​

int main() {
    int N, M, L, R, Num[1001], i, j, k, Temp;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
        scanf("%d", &Num[i]);
    }
    for (i = 0; i < M; i++) {
        scanf("%d%d", &L, &R);
        for (j = L - 1, k = R - 1; j < (R + L) / 2; j++, k--) {
            Temp = Num[j];
            Num[j] = Num[k];
            Num[k] = Temp;
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d", Num[i]);
        if (i != N - 1) printf(" ");
        if (i == N - 1) printf("\n");
    }
    return 0;
}

