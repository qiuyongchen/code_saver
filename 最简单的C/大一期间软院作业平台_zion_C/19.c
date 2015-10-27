妙处在于：求2的365次方时用了循环化简的思路

Description:

【Description】
Uncle Da is very smart.His IQ was just 0 on his birthday.But it grows 1 everyday.For example,
when Uncle Da is 1 year old,his IQ is 365!
Ziyao big god is smarter then Uncle Da.His IQ was 1 on his birthday,and grows 1 time every day.
For example, when Ziyao is 1 year old, his IQ is 2^365!!!
Uncle Da's IQ is x when he is n years old.Ziyao's IQ is y when he is m years old.
(We assume that  every year is 365 days)
Now a martian want to know how much is (y-x)%400009.
 
【input format】
 Two numbers, n and m.(x,y<=1000)
 
【output format】
A number, the value of (y-x)%400009,don't forget "\n".
 
【sample input】
1 1
 
【sample output】
275117
 
Note: If you have any question on the description, please send an email to its author.


#include <stdio.h>


int main() {
    int n, m;
    int y, x;
    int Mod = 1, Res, i;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= 365 * m; i++) {
        Mod = Mod * 2;
        Mod = Mod % 400009;
    }
    Res = Mod - n * 365;
    if (Res >= 0) {
        printf("%d\n", Res);
    } else {
        printf("%d\n", 400009 + Res);
    }
    return 0;
}


