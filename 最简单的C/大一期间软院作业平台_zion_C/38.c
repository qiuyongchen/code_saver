Description:

If you have any doubt on this assignment, please send an email to its author 何理达.
Description

歌手The Pancakes到幼儿园跟小朋友玩耍，她到达的时候小朋友们已经争着积木玩了。小朋友都想要更多的积木砌一个自己喜欢的图形，砌完就可以和The Pancakes合照。同时，The Pancakes手上还有一些积木，她可以把手上的这些积木全部给一个小朋友，然后等该小朋友砌完后就可以收回所发的积木和该小朋友原先手上的积木。但她不知道能否让所有的小朋友都和她合照，聪明的你可以帮助她吗？
Input

 
输入包含多个数据。
每个数据的第一行是两个正整数n和s，1≤n≤10000，1≤s≤1000000，表示一共有n位小朋友，The Pancakes手上有s块积木。以下有n行，每行有两个正整数，a和b，1≤a，b≤10^9，表示第i个小朋友手上有a块积木，还需要b块积木才能够砌完。
输入n=0时表示结束。
 
Output

如果可以让所有小朋友都和Pancake合照，就输出YES；否则，输出NO。
Sample Input

2 2
1 4
2 1
2 2
1 4
1 1
0 0
Sample Output

YES
NO
Problem Source

ZSUACM Team Member

Hint:

记得排序啊

Your answer:

#include <stdio.h>
 
int main() {
    long int n, s, flag, i, j, min, temp, a[10000], b[10000];
    do {
        scanf("%ld%ld", &n, &s);
        for (i = 0; i < n; i++) {
            scanf("%ld%ld", &a[i], &b[i]);
        }
 
        for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                if (b[j] < b[min]) {
                    temp = b[j]; b[j] = b[min]; b[min] = temp;
                    temp = a[j]; a[j] = a[min]; a[min] = temp;
                }
            }
        }
 
        flag = 1;
        for (i = 0; i < n; i++) {
            if (s >= b[i]) {
                s = s + a[i];
            } else {
                flag = 0;
            }
        }
        if (n != 0) {
            if (flag == 1) printf("YES\n");
            if (flag == 0) printf("NO\n");
        }
    } while (n != 0);
    return 0;
}

