/*
 Created by qiuyongchen.
 Time:2013/12/28 21:32.
 Usage:桌上有一叠牌，从第一张牌（即位于顶面的牌）开始从上往下依次编号为1~n。
 当至少还剩两张牌时进行以下操作：把第一张牌扔掉，然后把新的第一张放到整叠牌的最后。
 输入n,输出每次扔掉的牌，以及最后剩下的牌。
*/
#include <stdio.h>


int main() {
    int s, k, n, i, j, a[40];
    scanf("%d", &s);
    for ( k = 0; k < s; k++ ) {
        scanf("%d", &n);


        for ( i = 1; i <= n; i++ ) {
            a[i] = i;
        }


        // the most important part the program
        for ( i = 1; i < n; i++ ) {
            // Throw the first one of the current(just leave it in the original
            // array).


            // Then put the next one which is the 'new' first one int the
            // end(a[n+1])
            //
            a[n + 1] = a[i + 1];


            // pull them back.
            for ( j = i + 1; j <= n; j++ ) {
                a[j] = a[j + 1];
            }


        }


        for ( i = 1; i <= n; i++ ) {
            printf("%d ", a[i]);
        }


        printf("\n");
    }
    return 0;
}
