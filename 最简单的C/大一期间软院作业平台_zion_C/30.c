Good:

Making a new arrey to store the arrey without space.

Description:

If you have any doubt on this assignment, please send an email to its author 何理达.
Ziyao is a strange boy and he likes the sentence without blanks.
Give you a line of string, please output a a string that all blanks are removed.
[sample input]
2
aaa bbb        ccc
qwelkj lkjl l
[sample output]
aaabbbccc
qwelkjlkjll

Hint:

gets
getchar


#include <stdio.h>
#include <string.h>


int main() {
    int n, i, j, k, len;
    char s[100], ns[100];
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        gets(s);
        len = strlen(s);
        for (j = 0, k = 0; j < len; j++) {
            if (s[j] != ' ') {
                ns[k] = s[j];
                k++;
            }
        }
        len = strlen(ns);
        for (j = 0; j < k; j++) {
            putchar(ns[j]);
        }
        if (i != 0) printf("\n");
    }
    return 0;
}

