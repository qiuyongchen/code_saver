妙处在于：标准答案直接在while中进行运算，把b当做最后一个非零余数

Description:

Euclidean Algorithm, which we call 辗转相除法 in Chinese. Now I give you a simple example.
Given 319 and 377
377 / 319 = 1 with remainder 58
319 / 58 = 5 with remainder 29
58 / 29 = 2 with remainder 0
So, the GCD of 319 and 377 using Euclidean Algorithm is 29.

GCD means greatest common divisor. Now, given two integer a and b, please output the GCD of them, using Euclidean algorithm.
Note: If you have any question on the description, please send an email to its author.



#include <stdio.h>
 
int main() {
  int InpOne, InpTwo, Temp;
  int Shan, YuShu, FeiYuShu;
  scanf("%d%d", &InpOne, &InpTwo);
  if (InpTwo > InpOne) {
    Temp = InpOne;
    InpOne = InpTwo;
    InpTwo = Temp;
  }
  YuShu = InpOne % InpTwo;
  FeiYuShu = YuShu;
  InpOne = InpTwo;
  InpTwo = YuShu;
  if (YuShu == 0) {
     printf("%d\n", InpOne);
  } else {
    while (YuShu != 0) {
      FeiYuShu = YuShu;
      YuShu = InpOne % InpTwo;
      InpOne = InpTwo;
      InpTwo = YuShu;
    }
    printf("%d\n", FeiYuShu);
  }
  return 0;
}

标准答案：
#include <stdio.h>
int main(void) {
  int a, b;
  int t;
  scanf("%d%d", &a, &b);
  if (a < b) {
    t = a;
    a = b;
    b = t;
  }
  while (a % b != 0) {
      t = a % b;
      a = b;
      b = t;
  }
  printf("%d\n", b);
  return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

