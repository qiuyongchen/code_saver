Good:

Take the new one as the miniest one.

Description:

If you have any doubt on this assignment, please send an email to its author 黄珑.
Description

"Who is going to take away food?"
This is a software on the web:“ele.me", the man who has the smallest number have to take away food for others.
Now we know every people's number, please tell me which man will go to take away food.
If two men have the same smallest number, let  the laster one to go.
Input format

The first line has a number n (n<100), the number of people.
And for the last n lines, each line has a number , how great the man have. The number is a natural number and less than 100.
Output format

Just one line, the ID of the man, a white space, and "Wei Ren Min Fu Wu!".
Sample input

5
63
36
40
86
78
Sample output

2 Wei Ren Min Fu Wu!

#include <stdio.h>

int main() {
    int n, P[100], i = 0, Min = 100, To = -1;
    scanf("%d", &n);
    if (n == 0) {
        printf("0 Wei Ren Min Fu Wu!\n");
    } else {
        while (i < n) {
              scanf("%d", &P[i]);
              i++;
        }
        for (i = 0; i < n; i++) {
            if (P[i] <= Min) {
                Min = P[i];
                To = i + 1;
            }
        }
        printf("%d Wei Ren Min Fu Wu!\n", To);
    }
    return 0;
}





