/* Created by wlxead
   The value of the comma expression, now I know that,
the value of the comma expression is the rightmost
expression in the list, the type is the same
*/


/*What's more, it will do some caculation in the comma expression*/
#include <stdio.h>


/*function main begins program execution*/
int main () {
    int i = 2, j = 3;
    float a = 4.4;
    printf("%f\n", (i, j = 6, a));
    printf("%d    %d    %f\n", i, j, a);
    return 0;
} /*end function main*/
