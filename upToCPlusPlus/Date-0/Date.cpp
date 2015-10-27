#include "Date.h"
#include <iostream>

using namespace std;

void Date::reset() {
  set(2012,12,05);
}

void Date::set(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

void Date::fromStr(string str) {
  int i, j;
  int y, m, d;
  y = (str[0] - 48) * 1000 + (str[1] - 48) * 100 + (str[2] - 48) * 10;
  y = y + (str[3] - 48);
  m = (str[5] - 48) * 10 + (str[6] - 48);
  d = (str[8] - 48) * 10 + (str[9] - 48);
  set(y, m, d);  
}

string Date::toStr() const {
  char s[7]= "";
  cout << year << '-' << month << '-' << day;
  return s;
}
