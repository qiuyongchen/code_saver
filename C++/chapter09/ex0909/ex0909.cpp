// Created by YongchenQiu
// ex0909.cpp

#include "DateAndTime.h"
#include <iostream>
using namespace std;

int main() {
  DateAndTime dateTimeOne(11, 27, 1994, 23, 58, 45);

  for (int i = 0; i < 200; i++) {
    dateTimeOne.tick();
    dateTimeOne.printStandard();
    cout << endl;
    dateTimeOne.printUniversal();
    cout << endl << endl;
  }

  return 0;
}
