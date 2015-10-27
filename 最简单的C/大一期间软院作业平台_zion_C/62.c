/*
 Created by qiuyongchen.
 Time:2013/12/28 21:40.
 Usage:F[0]=0;


 F[1]=1;


 F[n]=F[n-1]+F[n-2], for n>1


 给出n (0<=n<=10000) 和 m (0<m<10000);求斐波那契数列第n项mod m的值(因为太大了);
*/


#include <stdio.h>


int main() {
    int F[10001], n, m, T, a, b, i, j;
    scanf("%d%d", &n, &m);
    F[0] = 0;
    F[1] = 1;


    for ( i = 2; i <=n; i++ ) {
        F[i] = (F[i - 1] + F[i - 2]) % m;
    }


    printf("%d\n", F[n]);
    return 0;
}
