// Created by YongchenQiu.
// DateAndTime.h
// class DateAndTime definition and implement.

#include <ctime>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#define CCT (+8)
using namespace std;

class DateAndTime {
 public:
  DateAndTime(int m = 1, int d = 1, int y = 2000, int h = 0,
	      int mi = 0, int s = 0); // default constructor
  void nextDay();
  void print();
  void setDate(int m, int d, int y);

  // set functions
  void setTime( int h, int m, int s); // set hour, minute, second
  void setHour( int h); // set hour (after validation)
  void setMinute( int m); // set minute (after validation)
  void setSecond( int s); // set second (after validation)

  // get functions
  int getHour(); // return hour
  int getMinute(); // return minute
  int getSecond(); // return second

  void printUniversal(); // output time in universal-time format
  void printStandard(); // output time in standard-time format

  void tick( void );

 private:
  int hour; // 0 - 23 (24-hour clock format)
  int minute; // 0 - 59
  int second; // 0 - 59

  bool leapYear();
  int daysMonth();

  int month;
  int day;
  int year;
}; // end class Date

// Date constructor (should do range checking)
DateAndTime::DateAndTime( int m, int d, int y, int h, int mi, int s ) {
  setDate(m, d, y);
  setTime(h, mi, s);
} // end constructor Date

// to set the date
void DateAndTime::setDate(int m, int d, int y) {

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
void DateAndTime::nextDay() {

  if (month == 12 && day == 31) {
    setDate(1, 1, year + 1);
  } else if (day == daysMonth()) {
    setDate(month + 1, 1, year);
  } else {
    setDate(month, day + 1, year);
  }

}

// to check if it is the leap year
bool DateAndTime::leapYear() {

  if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
    return true;
  } else {
    return false;
  }

}

// to get the number of days in the particular month
int DateAndTime::daysMonth() {
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((month == 2) && (leapYear())) {
    return days[month - 1] + 1;
  } else {
    return days[month - 1];
  }

}

// print Date in the format mm/dd/yyyy
void DateAndTime::print() {
  if (month < 10)
    cout << 0;
  cout  << month << '/';
  if (day < 10)
    cout << 0;
  cout << day << '/' << year;
} // end function print

// set new Time value using universal time
void DateAndTime::setTime( int h, int m, int s ) {
  setHour( h ); // set private field hour
  setMinute( m ); // set private field minute
  setSecond( s ); // set private field second
} // end function setTime

// set hour value
void DateAndTime::setHour( int h ) {
  if ( h >= 0 && h < 24 )
    hour = h;
  else
    throw invalid_argument( "hour must be 0-23" );
} // end function setHour

// set minute value
void DateAndTime::setMinute( int m ) {
  if ( m >= 0 && m < 60 )
    minute = m;
  else
    throw invalid_argument( "minute must be 0-59" );
} // end function setMinute

// set second value
void DateAndTime::setSecond( int s ) {
  if ( s >= 0 && s < 60 )
    second = s;
  else
    throw invalid_argument( "second must be 0-59" );
} // end function setSecond

// return hour value
int DateAndTime::getHour() {
  return hour;
} // end function getHour

// return minute value
int DateAndTime::getMinute() {
  return minute;
} // end function getMinute

// return second value
int DateAndTime::getSecond() {
  return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void DateAndTime::printUniversal() {
  print();
  cout << ' ';
  cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
       << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void DateAndTime::printStandard() {
  print();
  cout << " ";
  cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
       << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
       << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard

// increments the time store in a Tiem object by one second
void DateAndTime::tick( void ) {

  if ( hour == 23 && minute == 59 && second == 59 ) {
    setTime( 0, 0, 0 );
    nextDay();
  } else if ( minute == 59 && second == 59 ) {
    setTime( getHour() + 1, 0, 0 );
  } else if ( second == 59 ) {
    setTime( getHour(), getMinute() + 1, 0 );
  } else {
    setTime( getHour(), getMinute(), getSecond() + 1 );
  }

}
