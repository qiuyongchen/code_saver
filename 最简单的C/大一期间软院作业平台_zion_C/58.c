/*
 Created by qiuyongchen.
 Time:2013/12/28.
 Usage:Most positive integers may be written as a sum of a sequence
 of at least two consecutive positive integers. For instance,
 6 = 1 + 2 + 3 
 9 = 5 + 4 = 2 + 3 + 4
 but 8 cannot be so written.
 Write a program which will compute how many different ways an input
 number may be written as a sum of a sequence of at least two consecutive
 positive integers.
*/


#include <stdio.h>
#include <math.h>


int howMany(int M);


int main() {
    int N, M, i, j, b;
    scanf("%d", &N);


    for ( i = 1; i <= N; i++ ) {
        scanf("%d%d", &j, &M);
        printf("%d %d\n", i, howMany(M));
    }


    return 0;
}


int howMany(int M) {
    int num, i = 0, a, b, mid;
    for ( num = sqrt(M * 2); num > 0; num-- ) {


        // if 'num' is a OuShu.
        if ( num % 2 == 0 ) {
        mid = M / num;
        a = mid - num / 2 + 1;
        b = mid + num / 2;
        }


        // if 'num' is a JiShu.
        if ( num % 2 == 1 ) {
        mid = M / num;
        a = mid - num / 2;
        b = mid + num / 2;
        }


        // if [a,b] can get M.
        if ( (a + b) * (b - a + 1) / 2 == M ) {
             i++;
        }
    }
    return i - 1;
}
