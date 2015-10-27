Description:

If you have any doubt on this assignment, please send an email to its author 何理达.
请使用指针交换两个int型变量
[input]
2 3
[output]
3 2

Hint:

自觉使用指针啊

Your answer:


/* Something about ZhiZheng*/
#include <stdio.h>


/*function main begins program execution*/
int main () {
    int a, b, temp;
    int *p1 = &a, *p2 = &b;
    scanf("%d%d", &a, &b);
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("%d %d\n", a, b);
    return 0;
} /*end function main*/

