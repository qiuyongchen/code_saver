Description:

given a b and p, output (a^b) % p   (2<=a<=100, 0<=b<=1000000000,  3<=p<=10000)
Note: If you have any question on the description, please send an email to its author.

Hint:

快速幂
取模运算性质




#include <stdio.h>
int main() {
    unsigned int x, x1, n, p, ans = 1, i = 1;
    scanf("%d%d%d", &x, &n, &p);
    x = x % p;
    while (n > 0) {
        if (n % 2 == 1)
            ans = (ans * x) % p;
        n = n / 2;
        x = (x * x) % p;
    }
    printf("%d\n", ans);
    return 0;
}
