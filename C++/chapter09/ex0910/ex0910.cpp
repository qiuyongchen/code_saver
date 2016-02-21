// Created by YongchenQiu
// ex0910.cpp
#include <iostream>
#include "Time.h"
using namespace std;

int main() {
  Time tOne(0, 0, 0);
  tOne.printStandard();
  cout << endl;

  Time tTwo(-1, 0, 0);
  cout << endl;

  Time tThree(0, 78, 0);
  cout << endl;

  Time tFour(0, 0, 99);
  cout << endl;
  return 0;
}
