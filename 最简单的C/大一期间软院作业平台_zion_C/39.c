Description:

If you have any doubt on this assignment, please send an email to its author 汪欣言.
Design a function “solution(int,int,float)”, which is run to know the solutions of a equation.
 
设计一个函数solution(int,int,float)，计算方程的解。
只用提交子函数solution(int,int,float)的代码，主函数已给hint中给出。
 
 
Sample input:
1 2 1
Sample output:
-1.000 -1.000
 
Sample input:
2 2 2
Sample output:
Invalid!!
 
 
 

Hint:

求平方根可用<math.h>中的sqrt函数.
主函数：
#include <stdio.h>
#include <math.h>
float x1, x2, disc;
void solution(int r, int p, float q);
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    disc = b * b - 4 * a * c + 0.0;
    if (disc < 0) {
        printf("Invalid!!\n");
    } else {        
        solution(a, b, disc);
        printf("%.3f %.3f\n", x1, x2);
    }
    return 0;
}
 
 

Your answer:

Already pass (hard) due date: Nov. 26, 2013, 12:25 p.m.. You can no longer submit your code to smart_programmer by yourself.
We don't accept late submission in principle. But if you really have a convincing reason, send the answer code to your TA by email and ask her/him to submit it for you.
Don't copy the standard answer. It will be considered as plagirism.


#include <stdio.h>
#include <math.h>
float x1, x2;
void solution(int r, int p, float q) {
    x1 = (-p + sqrt(q)) / (2 * r);
    x2 = (-p - sqrt(q)) / (2 * r);
}
