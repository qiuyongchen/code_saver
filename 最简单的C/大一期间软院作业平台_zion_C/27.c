Good:

using functions of string && learn to use ASCII 9~57|0~48

Description:

If you have any doubt on this assignment, please send an email to its author 黄珑.
 

Constraints
Time Limit: 1 secs, Memory Limit: 8 MB
Description
 
Input A and B, output A+B
 
Input
 
Input two values, A and B.(0<=A,B<10^100)
 
Output
 
Output the result of A+B.
 
Sample Input
1234567890123456789
987654321
Sample Output
1234567891111111110
 

Hint:

A and B are large numbers，please use high precision computation.
 
A和B是非常大的数字，请使用高精度计算。

Your answer:


#include <stdio.h>
#include <string.h>


int main() {
    char A[100], B[100], Temp[100], Sum[100];
    int NA, NB, i, j, k;
    for (k = 0; k < 100; k++) Sum[k] = 48;
    scanf("%s%s", A, B);
    NA = strlen(A);
    NB = strlen(B);
//将最长序列放到A[100]中
    if (NB > NA) {
        snprintf(Temp, sizeof(Temp), A);
        snprintf(A, sizeof(A), B);
        snprintf(B, sizeof(B), Temp);
        NA = strlen(A);
        NB = strlen(B);
    }
//判断是否需要加个1
    if (NA == NB || NA - NB < 2) {
        if ((A[0] + B[0] - 48 > 57) || (A[0] + A[1] + B[0]  > 211))
            printf("1");
    }
//把B[]中的内容一个个加到A[]中去，若大于9则进位
    for (i = NB - 1, j = NA - 1; i >= 0; i--, j--) {
        if (A[j] + B[i] - 96 > 9) {
            A[j] = A[j] + B[i] - 48 - 10;
            A[j - 1] = A[j - 1] + 1;
        } else {
        A[j] = A[j] + B[i] - 48;
        }
    }
//利用一个小小的BUG，如果进位后还需要进位，则直接改掉要进位的地方而不再计算
    for (i = 0; i < NA; i++) {
        if (A[i] == ':') {
            A[i] = '0';
            A[i - 1] += 1;
        }
    }
    printf("%s\n", A);
    return 0;
}

