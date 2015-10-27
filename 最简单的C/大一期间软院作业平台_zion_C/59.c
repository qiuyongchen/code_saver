/*
 Created by qiuyongchen.
 Time:2013/12/28.
 Usage:经济的发展和社会的进步导致的新型经济板块的出现，使得首先占领新的经济板块的
 人获得了新的收入，贫富差距由此产生。小明对这个课题产生了浓厚的兴趣，并想出了一个
 评估贫富差距严重程度的方法。他先收集到N个整数数据，每个数据表示一个自然人的收入。
 然后他找出其中最大K个整数的中位数，还找出最小K个整数的中位数，将这两个中位数作差
 即可得到一个评估值。你能实现这样的一个算法吗？






 Input
 可能有多个测试输入，第一行给出总共的测试输入的个数M(0<M<1000)。


 对于每个测试输入，第一行包含两个正整数N和K，第二行包含一个大小为N的无序数组
 (0<N<100000,0<K<200,K<N)。


 Output
 输出一个整数，即最大K个整数中位数与最小K个整数中位数的差值。其中，计算过
 程中出现的除法均向下取整。






Sample Input
2
8 2
8 7 6 5 1 2 3 4
10 3
1 50 2 49 3 48 4 47 5 46
Sample Output
6
47
*/


#include <stdio.h>


int sortBubble(int b[10000], int x);


int main() {
    int M, N, K, i, j, k, a[100000], min, max;
    scanf("%d", &M);


    for ( i = 0; i < M; i++ ) {
        scanf("%d%d", &N, &K);


        for ( j = 0; j < N; j++ ) {
            scanf("%d", &a[j]);
        }


        sortBubble(a, N);


        if ( K % 2 == 1 ) {
            min = a[K / 2];
            max = a[N - 1 - K / 2];
            printf("%d\n", max - min);
        } else {
            printf("%d\n", (a[N - 1 - K / 2] + a[N - 1 - K / 2 + 1]) / 2
                              - (a[K / 2] + a[K / 2 - 1]) / 2);
        }


    }
    return 0;
}


int sortBubble(int b[10000], int x) {
    int pass, i, hold;


    for ( pass = 1; pass < x; pass++ ) {


        for ( i = 0; i < x - 1; i++ ) {


            if ( b[i] > b[i + 1] ) {
                hold = b[i];
                b[i] = b[i + 1];
                b[i + 1] = hold;
            }


        }


    }


    return 1;
}
