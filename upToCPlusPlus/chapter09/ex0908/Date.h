// Created by YongchenQiu.
// Date.h
// class Date definition and implement.

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Date {
 public:
  Date(int = 1, int = 1, int = 2000); // default constructor
  void nextDay();
  void print();
  void setDate(int m, int d, int y);

 private:
  bool leapYear();
  int daysMonth();
  int month;
  int day;
  int year;
}; // end class Date

// Date constructor (should do range checking)
Date::Date( int m, int d, int y ) {
  setDate(m, d, y);
} // end constructor Date

// to set the date
void Date::setDate(int m, int d, int y) {

  if (y > 0) {
    year = y;
  } else {
    throw invalid_argument ("wrong year!");
  }

  if (m > 0 && m < 13) {
    month = m;
  } else {
    throw invalid_argument ("wrong month!");
  }

  if (0 < d && d <= daysMonth()) {
    day = d;
  } else {
    throw invalid_argument ("wrong day!");
  }

}
// to increment day by one
void Date::nextDay() {

  if (month == 12 && day == 31) {
    setDate(1, 1, year + 1);
  } else if (day == daysMonth()) {
    setDate(month + 1, 1, year);
  } else {
    setDate(month, day + 1, year);
  }

}

// to check if it is the leap year
bool Date::leapYear() {

  if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
    return true;
  } else {
    return false;
  }

}

// to get the number of days in the particular month
int Date::daysMonth() {
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((month == 2) && (leapYear())) {
    return days[month - 1] + 1;
  } else {
    return days[month - 1];
  }

}

// print Date in the format mm/dd/yyyy
void Date::print() {
  if (month < 10)
    cout << 0;
  cout  << month << '/';
  if (day < 10)
    cout << 0;
  cout << day << '/' << year << endl;
} // end function print

