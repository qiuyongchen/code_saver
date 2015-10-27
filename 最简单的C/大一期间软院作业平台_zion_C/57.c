Description:

如果你对作业有任何疑问，请发邮件给出题人黄珑.
 
Easy search

    Giving you an integer set P and a number X, try to judge if X is belong to the set P.
    Now we have the main function :
#include <stdio.h>
    int search(int *p, int n, int x);
    int n, p[1000000], i, x, ans;
    int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &p[i]);
    scanf("%d", &x);
    ans = search(p, n, x);
    if (ans == -1) puts("No"); else printf("%d\n", ans);
}
    Now you have to write the function "int search(int *p,  int n, int x)", to find where the x is in the set.
    *p is the pointer of the set, n means there are n numbers in set P, and x is the number to find.
    Return a integer, means the position of the x in the set P.If you can not find x in p, return -1. And if there are more than one numbers equal to x, choose the smallest one.
 
SAMPLE  INPUT
(1)
5
1 2 3 4 5
3
(2)
5
1 2 3 4 5
10
(3)
3
1 2 2
2
SAMPLE OUTPUT
(1)
2
(2)
No
(3)
1

Hint:

If I have something wrong, please mail to me, because I'm too week in point. Thank you.

你的答案：


int search(int *p,  int n, int x) {
    int i;


    for ( i = 0; i < n; i++ ) {
        if ( p[i] == x ) {
            return i;
        }
    }


    return -1;
}

