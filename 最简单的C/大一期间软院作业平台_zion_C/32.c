Description:

If you have any doubt on this assignment, please send an email to its author 汪欣言.
Sn = a + aa + aaa + ... + aa...aa(the number of a is n).Input a and n on your own, calculate its output.(0<a<10,n<100)
 

Hint:

标准答案（有错版）：
#include <stdio.h>
int main() {
    long long int a, n, i, sn, tn;
    i = 1;
    sn = 0;
    tn = 0;
    scanf("%lld %lld", &a, &n);
    while (i <= n) {
        tn = tn + a;
        sn = sn + tn;
        a = a * 10;
        i++;
    }
    printf("%lld\n", sn);
    return 0;
}
我的答案（有错版）：
#include <stdio.h>

int main() {
    long a, n, sum = 0, sumT = 0;
    int i;
    scanf("%ld%ld", &a, &n);
    for (i = n; i > 0; i--) {
        sum = sum * 10 + a;
        sumT = sumT + sum;
    }
    printf("%ld\n", sumT);
    return 0;
}

我的答案（正确高精度版）：
#include <stdio.h>
int main() {
    int a, n, i, j, b[150] = {0};
    scanf("%d%d", &a, &n);
    for (i = 0; i < n; i++) {
        b[i] = a * (n - i);
    }
    for (i = 0; b[i] != 0; i++) {
        b[i + 1] = b[i + 1] + b[i] / 10;
        b[i] = b[i] % 10;
    }
    for (j = i - 1; j >= 0; j--) {
        printf("%d", b[j]);
    }
    printf("\n");
    return 0;
}
conclusion:明显，出这题的TA脑子有问题。


Description:

If you have any doubt on this assignment, please send an email to its author 汪欣言.
Sn = a + aa + aaa + ... + aa...aa(the number of a is n).Input a and n on your own, calculate its output.(0<a<10,n<100)
 

Hint:

标准答案（有错版）：
#include <stdio.h>
int main() {
    long long int a, n, i, sn, tn;
    i = 1;
    sn = 0;
    tn = 0;
    scanf("%lld %lld", &a, &n);
    while (i <= n) {
        tn = tn + a;
        sn = sn + tn;
        a = a * 10;
        i++;
    }
    printf("%lld\n", sn);
    return 0;
}
我的答案（有错版）：
#include <stdio.h>

int main() {
    long a, n, sum = 0, sumT = 0;
    int i;
    scanf("%ld%ld", &a, &n);
    for (i = n; i > 0; i--) {
        sum = sum * 10 + a;
        sumT = sumT + sum;
    }
    printf("%ld\n", sumT);
    return 0;
}

我的答案（正确高精度版）：
#include <stdio.h>
int main() {
    int a, n, i, j, b[150] = {0};
    scanf("%d%d", &a, &n);
    for (i = 0; i < n; i++) {
        b[i] = a * (n - i);
    }
    for (i = 0; b[i] != 0; i++) {
        b[i + 1] = b[i + 1] + b[i] / 10;
        b[i] = b[i] % 10;
    }
    for (j = i - 1; j >= 0; j--) {
        printf("%d", b[j]);
    }
    printf("\n");
    return 0;
}
conclusion:明显，出这题的TA脑子有问题。


Good：

Some is terrible.

Description:

If you have any doubt on this assignment, please send an email to its author 林培泳.
There are N people standing  in a row from left to right ,and each people i has height Hi. There are M queries, Each query has a number x,print the height of highest guy from position x to position n.
 
The  first line contains two integers N,M. (1<=N,M<=100000)
The second line describe N numbers in sequence.
The Next M lines,each line has a integer x,print the height of highest guy in x to right(including x)
 
Output M line, each lines  corresponds to an inquiry.

Hint:

NONE



#include <stdio.h>


int main() {
    int N, M,  Num[1001], i, j, k, Temp, Hig;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
        scanf("%d", &Num[i]);
    }
    for (i = 0; i < M; i++) {
        scanf("%d", &Temp);
        Hig = -1;
        for (j = Temp - 1; j < N; j++) {
            if (Num[j] > Hig) {
                Hig = Num[j];
            }
        }
        printf("%d\n", Hig);
    }
    return 0;
}


