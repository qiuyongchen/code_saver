Description:

计算斐波那契数列值
输入一个正整数，计算出刚好小于或等于这个正整数的斐波那契数列项的值（包括0）
输入： 本题有多个测试样例；
第一行为一个正整数t，表示样例组数
第二至第t+1行都是一个正整数（<=100000）
输出： 每一行一个样例结果，输出小于等于输入数的最大的一项斐波那契数;
样例:
输入:
2
3
5
输出:
3
5

Hint:

#include <stdio.h>

int main() {
  int Num;
  int Tt[100];
  int Temp = 1;
  int FedOne = 0, FedTwo = 1, FedSum;
  int FedLess;
  scanf("%d", &Num);
  while (Temp <= Num) {
    scanf("%d", &Tt[Temp]);
    Temp++;
  }
  Temp = 1;
  while (Temp <= Num) {
    FedOne = 0;
    FedTwo = 1;
    FedLess = FedOne;
    while (FedLess <= Tt[Temp]) {
    FedSum = FedOne + FedTwo;
    FedLess = FedSum;
    FedOne = FedTwo;
    FedTwo = FedSum;
    }
  if (FedLess <= Tt[Temp])
    printf("%d\n", FedLess);
  else
    printf("%d\n", FedOne);
    Temp++;
  }
  return 0;
}
