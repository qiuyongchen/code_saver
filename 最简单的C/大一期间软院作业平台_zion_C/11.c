妙处在于：最小公因数=两个数相乘/最大公约数

Description:

LCM, Least Common Multiple. Now, give you two integer a and b, output their LCM.
[Example Input]
338 510
[Example Output]
86190
Note: If you have any question on the description, please send an email to its author.



#include <stdio.h>


int main() {
  int InpOne, InpTwo, Temp, a, b;
  int Shan, YuShu, Gong;
  scanf("%d%d", &InpOne, &InpTwo);
  a = InpOne;
  b = InpTwo;
  if (InpTwo > InpOne) {
    Temp = InpOne;
    InpOne = InpTwo;
    InpTwo = Temp;
  }
  while (InpOne % InpTwo != 0) {
    YuShu = InpOne % InpTwo;
    InpOne = InpTwo;
    InpTwo = YuShu;
  }
  if (YuShu != 0) {
    Gong = a * b / YuShu;
    printf("%d\n", Gong);
  } else {
    printf("%d\n", a * b);
  }
  return 0;
}

