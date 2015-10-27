/*Created by wlxead
  Time:
  To know if switch need braces and some usage of EOF
*/


/*It do, in deed, not need braces.
And, 'CTR + z' means EOF*/
#include <stdio.h>


/*function main begins program execution*/
int main () {
    int a, b = 'b';
    while ( (a = getchar()) != EOF) {
        switch (a) {
            case 'a':
                printf("%d    ", a);
                printf("%d\n", b);
                break;
            /*There are something amazing here, after the 'break' statement,
              the machine will run the 'c = getchar()' autotically and, more
              terriblly, a wiil be assigned as '\n'*/
            case ' ':
                printf("Sorry, you input a ' '\n");
                break;
            /*My god, it will put in all the characters I input before(including
              ' ' and '\n' )!*/
            case '\n':
                printf("Sorry, you input a '\\n'\n");
                break;
        }
    }
    return 0;
} /*end function main*/
