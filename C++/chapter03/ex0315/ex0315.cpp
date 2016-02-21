// ex0315.cpp
// Created by qiuyongchen.
#include <iostream>
#include <string>
using namespace std;

#include "Date.h"

int main() {
  Date dateOne(3, 4, 2019);
  dateOne.displayDate();
  dateOne.setMonth(12);
  dateOne.setDay(23);
  dateOne.setYear(1998);
  dateOne.displayDate();

  Date dateTwo;
  dateTwo.displayDate();
  dateTwo.setMonth(888);
  dateTwo.displayDate();

  return 0;
}
