// Date.h
// The definition and the implement of the Date class.
// Created by YongchenQiu
#include <iostream>
#include <ctime>
#include <string>
#include <stdexcept>
using namespace std;

class Date {
 public:
  static const int monthsPerYear = 12; // number of months in a year

  Date(char c);
  Date(int DDD = 1, int YYYY = 2000);
  Date(string MDY = "01/01/2000", int flag = 0);
  Date(string M = "June", string DY = "14,2000");

  bool leapYear(int y) const;
  void print() const;
  ~Date();
 private:
  int month; // 1-12 (January-December)
  int day; // 1-31 based on month
  int year; // any year
  // utility function to check if day is proper for month and year
  int checkDay(int d) const;
};

Date::Date(char) {
  time_t rawTime;
  struct tm *y2k;
  time(&rawTime);

  y2k = gmtime(&rawTime);

  day = y2k->tm_mday;
  month = y2k->tm_mon + 1;
  year = y2k->tm_year + 1900;
}



Date::Date(int DDD, int YYYY) {
  if (YYYY < 0)
    throw invalid_argument ("Bad YYYY!");
  else
    year = YYYY;

  int dPMonth[13] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int daySum;
  int dayOfYear = 365;
  if (leapYear(year)) {
    dPMonth[2] = 29;
    dayOfYear = 366;
  }

  int i;
  if (0 < DDD && DDD < dayOfYear) {
    daySum = DDD;
    for (i = 1; daySum > dPMonth[i];) {
      daySum = daySum - dPMonth[i];
      i++;
    }
    month = i;
    day = daySum;
  } else {
    throw invalid_argument("bad DDD!");
  }

}

Date::Date(string MDY, int flag) {
  int m = (MDY[0] - 48) * 10 + (MDY[1] - 48);
  int d = (MDY[3] - 48) * 10 + (MDY[4] - 48);
  int y = (MDY[6] - 48) * 10 + (MDY[7] - 48);

  year = 2000 + y;
  month = m;
  if (checkDay(d))
    day = d;
}

Date::Date(string M, string DY) {
  string monthNames[12] = {"January", "February", "March", "April", "May"
			   , "June", "July", "August", "September", "October"
			   , "November", "December"};
  for (int i = 0; i < 12; i++) {
    if (M == monthNames[i])
      month = i + 1;
  }
  day = (DY[0] - 48) * 10 + (DY[1] - 48);
  year = (DY[3] - 48) * 1000 + (DY[4] - 48) * 100 + (DY[5] - 48) * 10 + (DY[6] - 48);
}

bool Date::leapYear(int y) const {

  if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    return true;
  else
    return false;

}

// print Date object in form month/day/year
void Date::print() const {
  int DDD = 0;
  int dPMonth[13] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if (leapYear(year)) {
    dPMonth[2] = 29;
  }
  for (int i = 1; i <= month; i++) {
    DDD += dPMonth[i];
  }
  if (DDD < 100)
    cout << "0";
  cout << DDD << " " << year << endl;


  if (month < 10)
    cout << "0";
  cout << month << '/';
  if (day < 10)
    cout << "0";
  cout << day << '/';
  if (year % 100 < 10)
    cout << "0";
  cout << year % 100 << endl;


  string monthNames[12] = {"January", "February", "March", "April", "May"
			   , "June", "July", "August", "September", "October"
			   , "November", "December"};
  cout << monthNames[month - 1] << " " << day << ',' << year << endl;
} // end function print

// output Date object to show when its destructor is called
Date::~Date() {
  cout << "Date object destructor for date ";
  cout << endl;
} // end ~Date destructor

// utility function to confirm proper day value based on
// month and year; handles leap years, too
int Date::checkDay( int testDay ) const {
  static const int daysPerMonth[ monthsPerYear + 1 ] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  // determine whether testDay is valid for specified month
  if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
    return testDay;
  // February 29 check for leap year
  if ( month == 2 && testDay == 29 && ( year % 400 == 0 ||
					( year % 4 == 0 && year % 100 != 0 ) ) )
  return testDay;
  throw invalid_argument( "Invalid day for current month and year" );
} // end function checkDay
