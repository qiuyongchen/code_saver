// Date.h
// The declaration and definition of the Date class.
#include <iostream>
#include <string>
using namespace std;

class Date {
 public:
  Date(int m = 1, int d = 1, int y = 2014);
  void setMonth(int m);
  int getMonth() const;
  void setDay(int d);
  int getDay() const;
  void setYear(int y);
  int getYear() const;
  void displayDate() const;
 private:
  int month;
  int day;
  int year;
};

// The constructor of the Date class.
Date::Date(int m, int d, int y) {
  setMonth(m);
  setDay(d);
  setYear(y);
}

// Set the month.
// If m < 1 or m > 12, then month is set to 1.
void Date::setMonth(int m) {

  if (1 <= m && m <=12) {
    month = m;
  } else {
    month = 1;
  }

}

int Date::getMonth() const {
  return month;
}

// Set the day.
void Date::setDay(int d) {
  day = d;
}

int Date::getDay() const {
  return day;
}

// Set the year.
void Date::setYear(int y) {
  year = y;
}

int Date::getYear() const {
  return year;
}

void Date::displayDate() const {
  cout << month << '/' << day << '/' << year << endl;
}
