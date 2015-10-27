/* Created by wlxead
   To jusity the value of the assignment expressin
*/

/*So, the value of a assignment statement is the value 
of the variable in the left of the '=', and if will 
influence the value of b*/
#include <stdio.h>


/*function main begins program execution*/
int main () {
    int a, b, c;
    a = b = c = 0;
    printf("%d%d%d\n", a, b, c);
    a = b = (c = 1);
    printf("%d%d%d\n", a, b, c);
    b = c = 6;
    a = b;
    printf("%d%d%d\n", a, b, c);
    return 0;
} /*end function main*/
