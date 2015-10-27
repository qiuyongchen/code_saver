妙处在于：把一大堆的输入输出放在一个循环中而不用数组

Description:

输入一个整数，从最高位起依次输出每一位上的数字，用空格隔开。
 
Input sample
3
1256
0
1545
 
Output
1 2 5 6
0
1 5 4 5
Note: If you have any question on the description, please send an email to its author.


#include <stdio.h>


int main() {
  int n, i = 1, Num, j, J, a[1000];
  long int Input;
  scanf("%d", &n);


  while (i <= n) {
    j = 1000;
    J = 1000;
    scanf("%d", &Input);
    if (Input == 0) printf("0");
    while (Input > 0) {
      j--;
      a[j] = Input % 10;
      Input = Input / 10;
    }
    while (j < J) {
      printf("%d", a[j]);
      if (j <= J -2) printf(" ");
      j++;
    }
    i++;
    printf("\n");
  }


return 0;
}

