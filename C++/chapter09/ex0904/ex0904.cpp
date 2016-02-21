// ex0904.cpp
// Created by Yongchen Qiu.
#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

int main() {
  Time tOne;

  tOne.printUniversal();
  cout << endl;
  tOne.printStandard();
  cout << endl;

  return 0;
}
