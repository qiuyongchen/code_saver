// Created by YongchenQiu.
// ex0908.cpp
// the main function of the program is here

#include "Date.h"
#include <iostream>
using namespace std;

int main() {
  Date dateOne(11, 23, 2009);
  dateOne.print();

  for (int i = 0; i < 1200; i++) {
    dateOne.nextDay();
    dateOne.print();
  }

  return 0;
}
