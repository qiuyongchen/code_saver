#include "date.h"
#include <iostream>
#include <string>
using namespace std;

date::date(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

bool date::isleap() {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int date::daypass() {
  int temp = 0;

  if (isleap()) {
    for (int i = 0; i < month - 1; i++) {
      temp += monthoflpyr[i];
    }
  } else {
    for (int i = 0; i < month - 1; i++) {
      temp += monthofyr[i];
    }
  }

  return temp + day;
}
