Good:

functions
Description:

Write two functions GCD and LCM.GCD is greatest common divisor and LCM is The least common multiple.
You should only submit the statement of the two functions.
And the main function in our system:
#include <stdio.h>
    int main() {
    int a, b;
    int GCD(int, int);
    int LCM(int, int);
    scanf("%d%d", &a, &b);
    printf("%d %d\n", GCD(a, b), LCM(a, b));
    return 0;
}
写两个简单的函数GCD和LCM。GCD表示最大公约数，LCM表示最小公倍数。
你只需要提交这两个函数的定义就可以。
我们系统中的main函数如上。
Note: If you have any question on the description, please send an email to its author.

Hint:

Learn how to definition and call a function.
Try to use Recursive to calculation problem.
Although you must only submit the function statements,but you should write a main function in your computer, so that you can run and verification your code is correct or not.
 
学会如何去定义并且调用一个函数。
尝试着用递归去解决问题。
虽然题目只要求你交函数的声明，但是你还是应该自己把main函数在自己电脑上写出来，才能自己运行以验证写的函数是否正确。





int GCD(int a, int b) {
  int t;
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
  return b;
}

int LCM(int a, int b) {
  int t;
  if (a < b) {
    t = a;
    a = b;
    b = t;
  }
  t = 1;
  while (a * t % b != 0) {
    ++t;
  }
  return a * t;
}
