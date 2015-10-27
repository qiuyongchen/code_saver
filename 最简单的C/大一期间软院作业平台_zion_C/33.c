/*Created by 邱永臣
  Time:2013年12月9日
  
Description

The rabbits have powerful reproduction ability. One pair of adult rabbits can 
give birth to one pair of kid rabbits every month. And after m months, the kid 
rabbits can become adult rabbits.


    As we all know, when m=2, the sequence of the number of pairs of rabbits in
    each month is called Fibonacci sequence. But when m<>2, the problem seems 
    not so simple. You job is to calculate after d months, how many pairs of 
    the rabbits are there if there is exactly one pair of adult rabbits 
    initially. You may assume that none of the rabbits dies in this period.


 


Input


The input may have multiple test cases. In each test case, there is one line 
having two integers m(1<=m<=10), d(1<=d<=100), m is the number of months after 
which kid rabbits can become adult rabbits, and d is the number of months after
which you should calculate the number of pairs of rabbits. The input will be
terminated by m=d=0.


Output


You must print the number of pairs of rabbits after d months, one integer per 
line.


Sample Input


2 3
3 5
1 100
0 0
Sample Output


5
9
1267650600228229401496703205376
*/


#include <stdio.h>
int s[100][33] = {0};


/*高精度计算，注意j>=1而不是j>=0,注意是先加再模和先加再除。*/
void higherPlus(int *a, int *b, int *c) {
    int j, temp;
    for (j = 32; j >= 1; j--) {
        temp = a[j];
        a[j] = (temp + b[j] + c[j]) % 10;
        a[j - 1] = (temp + b[j] + c[j]) / 10;
    }
}


/*function f is used to work out the number of rabbits.s[i] means the ith day
and s[i][] is used to means the 高精度计算*/
void f(int m, int d) {
    int i;
    for (i = 1; i <=m; i++) {
        s[i][32] = i + 1;
        if (i == 9) {
            s[i][32] = 0;
            s[i][31] = 1;
        }
        if (i == 10) {
            s[i][32] = 1;
            s[i][31] = 1;
        }
    }
    for  (i = m + 1; i <= d; i++) {
        higherPlus(s[i], s[i - 1], s[i - m]);
    }
}


/*function main begins program execution*/
int main() {
    int m, d, i, flag, j, k;
    scanf("%d%d", &m, &d);
    while (m != 0 && d != 0) {
        flag = 0;
        f(m, d);


        for (i = 0; i < 33; i++) {
            if (s[d][i] != 0) flag = 1;
            if (s[d][i] != 0 || flag == 1) printf("%d", s[d][i]);
        }
        printf("\n");


        for (j = 0; j < 100; j++)
            for (k = 0; k < 33; k++)
                s[j][k] = 0;


        scanf("%d%d", &m, &d);


    }
    return 0;
} /*end function main*/
