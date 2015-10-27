
Good:

Give a number to a arrey like : snprintf(*Dig[5], sizeof(Dig[5]) + 1, "+----|    +---+    |----+");

Description:

If you have any doubt on this assignment, please send an email to its author 黄珑.
Constraints

Time Limit: 1 secs, Memory Limit: 8 MB
Description

 
Input A and B, output A+B you draw with some words as '-' , '|' , '+' , ' '(space) .
 
Input

 
Input two values, A and B.(0<=A,B<=1,000,000,000)
 
Output

 
Output five lines,show the picture of A+B.
For each line, each digit have 5 words,ans there is white space between every nearby two number.
The words of ten digits are below,if you are not sure what they are, you can see and copy.(from 0 to 9,each five line for one digit)
+---+
|   |
|   |
|   |
+---+
    |
    |
    |
    |
    |
----+
    |
+---+
|    
+----
----+
    |
----+
    |
----+
|   |
|   |
+---+
    |
    |
+----
|    
+---+
    |
----+
+----
|    
+---+
|   |
+---+
----+
    |
    |
    |
    |
+---+
|   |
+---+
|   |
+---+
+---+
|   |
+---+
    |
----+
Sample Input1

200000000 13456789
Sample Output1


Sample Input2

0 0
Sample Output2


Hint:

Play table:For each digit 0~9,there are 5*5 chars, you can save them in arrays before using
</h2>
#include <stdio.h>
#include <string.h>


int main() {
    int A, B, Sum, AB[100], ABN, ABJ, i = 0, j, k;
    char Dig[10][5][5];
    snprintf(*Dig[0], sizeof(Dig[0]) + 1, "+---+|   ||   ||   |+---+");
    snprintf(*Dig[1], sizeof(Dig[1]) + 1, "    |    |    |    |    |");
    snprintf(*Dig[2], sizeof(Dig[2]) + 1, "----+    |+---+|    +----");
    snprintf(*Dig[3], sizeof(Dig[3]) + 1, "----+    |----+    |----+");
    snprintf(*Dig[4], sizeof(Dig[4]) + 1, "|   ||   |+---+    |    |");
    snprintf(*Dig[5], sizeof(Dig[5]) + 1, "+----|    +---+    |----+");
    snprintf(*Dig[6], sizeof(Dig[6]) + 1, "+----|    +---+|   |+---+");
    snprintf(*Dig[7], sizeof(Dig[7]) + 1, "----+    |    |    |    |");
    snprintf(*Dig[8], sizeof(Dig[8]) + 1, "+---+|   |+---+|   |+---+");
    snprintf(*Dig[9], sizeof(Dig[9]) + 1, "+---+|   |+---+    |----+");
    scanf("%d%d", &A, &B);
    Sum = A + B;
    if (Sum == 0) {
        AB[0] = 0;
        ABN = 0;
    } else {
        while (Sum > 0) {
            AB[i] = Sum % 10;
            i++;
            Sum = Sum / 10;
        }
        ABN = i - 1;
    }
    for (i = 0; i <= 4; i++) {
        for (j = ABN; j >=0; j--) {
            for (k = 0; k <= 4; k++) {
                ABJ = AB[j];
                printf("%c", Dig[ABJ][i][k]);
            }
            if (j != 0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}



</h2>
