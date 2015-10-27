/************************************************************************************
   中缀表达式转后缀表达式遵循以下原则：
    1.遇到操作数，直接输出；
    2.栈为空时，遇到运算符，入栈；
    3.遇到左括号，将其入栈；
    4.遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出；
    5.遇到其他运算符'+''-''*''/'时，弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈；
    6.最终将栈中的元素依次出栈，输出。
    经过上面的步骤，得到的输出既是转换得到的后缀表达式。
/***********************************************************************************/
#include "MidToLast.h"
#include "stack.h"
#include <string>
#include <iostream>
using namespace std;

bool isOperator(char c) {
  if (c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')')
    return true;
  else
    return false;
}

int precedence(char c, bool flag) {
  if (c == '+' || c == '-') {
    return 1;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if ((c == '(' || c == ')') && flag) {
    return 0;
  } else if ((c == '(' || c == ')') && (!flag)) {
    return 3;
  } else {
    return -1;
  }
}

string MidToLast::transfer(string str) {
  string forReturn;
  int len = str.length();
  Stack sta;

  for (int i = 0; i < len; i++) {

    // 1.遇到操作数，直接输出；
    if (!isOperator(str[i])) {
      forReturn += str[i];
    } else {

      // 2.栈为空时，遇到运算符，入栈；
      if (sta.empty()) {
	sta.push(str[i]);
      } else {

	// 3.遇到左括号，将其入栈；
	if (str[i] == '(') {
	  sta.push(str[i]);

	  // 4.遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出
	} else if (str[i] == ')') {

	  while (sta.top() != '(') {
            forReturn += sta.top();
	    sta.pop();
	  }

	  // (弹出左括号)
	  sta.pop();

	  // 5.遇到其他运算符'+''-''*''/'时，弹出所有优先级大于或等于
	  //   该运算符的栈顶元素，然后将该运算符入栈
	} else if (isOperator(str[i])) {

	  while ((!sta.empty()) && (precedence(sta.top(), true)
				    >= precedence(str[i], false))) {
              forReturn += sta.top();
	      sta.pop();
	    }

	    sta.push(str[i]);

	}

      }

    }

  }

  // 6.最终将栈中的元素依次出栈，输出。
  while(!sta.empty()) {
    forReturn += sta.top();
    sta.pop();
  }

  return forReturn;
}
