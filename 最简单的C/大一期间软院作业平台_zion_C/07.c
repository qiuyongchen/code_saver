Description:

Given two pair of integers (a1, b1) and (a2, b2), output the expanded form of (a1*x + b1) * (a2 * x + b2).
 
[Example input]
4 2
5 7
[Example output]
20x^2+38x+14
Note: If you have any question on the description, please send an email to its author.

#include <stdio.h>
 
int main() {
  int a1, a2, b1, b2;
  int sum1, sum2, sum3;
  scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
  sum1 = a1 * b1;
  sum2 = a1 * b2 + a2 * b1;
  sum3 = a2 * b2;
  printf("%dx^2+%dx+%d\n", sum1, sum2, sum3);
  return 0;
}
