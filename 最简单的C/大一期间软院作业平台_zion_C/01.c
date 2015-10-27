
Description:

输入一个数，判断其是否为素数；
本题有多组测试样例。
输入规则如下：
第一行为一个整数，样例组数T；
第二至第t+1行每行都有一个整数a(a >= 2)，表示需要处理的数；
如果是素数则输出“yes”，否则输出“no”，每个样例的输出占1行；
输入输出样例：
输入：
2
99
17
输出：
no
yes

Hint:

#include <stdio.h>

int main() {
  int t;
  int tt[100];
  int temp = 1;
  int inp;
  int i = 2;
  int a = 0;

  scanf("%d", &t);
  while (temp <= t) {
    scanf("%d", &tt[temp]);
    temp++;
  }

  temp = 1;
  while (temp <= t) {
    a = 0;
    i = 2;
    while (i < tt[temp]) {
      if (tt[temp]%i == 0)a = 1;
      i++;
      }
      if (a == 1) {
        printf("no\n");
      } else {
        printf("yes\n");
      }
    temp++;
  }
  return 0;
}



