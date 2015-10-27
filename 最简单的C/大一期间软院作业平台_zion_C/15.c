妙处在于：把字符当做整型数来运算

Description:

输入一个字符串（可包含字母、空格、数字、其他符号等），依次计算其中字母个数、空格个数、数字个数及其他符号个数，并按此顺序输出。
 
Sample input:
I am a student.
 
Output:
11 3 0 1
 
Sample input:
Hello world，class 4！
 
Output:
15 2  1 2
 
Note: If you have any question on the description, please send an email to its author.


#include <stdio.h>
#include <stdlib.h>


int main() {
  char c;
  int LetterNum = 0, PlaceNum = 0, NumberNum = 0, ElseNum = 0;
  while ((c = getchar()) != '\n') {
    if ((c >= 65)&&(c <= 90) ||(c <= 122) && (c >= 97)) {
      LetterNum++;
    }
    else if ((c >= 48)&&(c <= 57)) {
      NumberNum++;
    }
    else if (c == 32) {
      PlaceNum++;
    } else {
      ElseNum++;
    }
  }
  printf("%d %d %d %d", LetterNum, PlaceNum, NumberNum, ElseNum);
  return 0;
}

