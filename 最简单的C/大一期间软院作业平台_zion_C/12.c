妙处在于：能被90除掉的数必有个0，且至少有9个5

Description:

[DESCRIPTION]
Ziyao Big God has n cards, each card has either digit 0 or digit 5, Ziyao is very egg pain, he want to know what is the largest possible number divisible by 90 he can make from the cards.

[Input]
The first line is an integer n(1 <= n <= 10^3), the next line contains n integers a1, a2, ..., an, which represents the digit that is written on the i-th card.
[Output]
output the answer, if such number does not exist, then output -1.

[Example input]
4
5 0 5 0
[Example output]
0

[Example input]
11
5 5 5 5 5 5 5 5 0 5 5
[Example output]
5555555550

[Example input]
1
5
[Example output]
-1
Note: If you have any question on the description, please send an email to its author.




#include <stdio.h>


int main() {
  int Input, IfZero = 0, NumFive = 0, NumNine, n, i = 1;
  scanf("%d", &n);
  while (i <= n) {
    scanf("%d", &Input);
    if (Input == 0) {
      IfZero = 1;
    } else if (Input == 5) {
      NumFive++;
    }
    i++;
  }
  if (IfZero == 0) {
    printf("-1\n");
  }
  else if (NumFive < 9) {
      printf("0\n");
  } else {
    NumNine = (NumFive / 9) * 9;
    for (i = 1; i <= NumNine; i++) printf("5");
    for (i = 1; i <= n-NumFive; i++) printf("0");
    printf("\n");
  }
  return 0;
}

