Good:

Using two functions which are useful ang connect each other

Description:

The Earth is familiar to us. However, seldom people know Brother WU’s world because his world is mysterious. It is said that anyone who wants to enter Brother WU's world must solve the problem below.
This is an easy problem.
For any nonnegative number N，define D(N) as the sum of (every odd number) and (two times every even number) in “N”.
Example：D(789) = 7 + 8 * 2 + 9 = 32, D(123456) = 1 + 2 * 2 + 3 + 4 * 2 + 5 + 6 * 2 = 33. 
F(N) is the ones place of D(N)。Example：F(789) = 2, F(123456) = 3。
The problem is，given A, B，you need to calculate ∑F(i), i ∈ [A, B]
Hurry to enter Brother WU's world. He has spent his entire life alone in his world.
 
输入格式
第一行输入一个整数T，表述有T组case。(T <=1000)
接下来T行，每行输入两个数字A, B （0 <= A <= B <= 400,000,000）
​
输出格式
每一行输出一个整数，表示题目所要求的和。

输入样例
3
1 8
28 138
123456 123456

输出样例
36
495
3
Note: If you have any question on the description, please send an email to its author.

Hint:

Brother WU is very lone.




#include <stdio.h>
int Dunc(int x) {
    int Num = 0, n, Sum = 0;
    while (x > 0) {
        n = x % 10;
        if (n % 2 == 1) Sum = Sum + n;
        else Sum = Sum + n * 2;
        x = x / 10;
    }
    return Sum;
}
int Func(int x) {
    int Sum;
    Sum = x % 10;
    return Sum;
}

int main() {
    int T, A, B, i, Sum = 0, x;
    int Dunc(int x);
    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d%d", &A, &B);
        while (A <= B) {
            x = Dunc(A);
            Sum = Sum + Func(x);
            A++;
        }
        printf("%d\n", Sum);
        Sum = 0;
    }
    return 0;
}
