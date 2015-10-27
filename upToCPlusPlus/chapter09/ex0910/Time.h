#include <ctime>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#define CCT (+8)
using namespace std;

// Time abstract data type definition
class Time
{
 public:
  Time( int h, int m, int s ); // default constructor

  // set functions
  void setTime( int h, int m, int s); // set hour, minute, second
  int setHour( int h); // set hour (after validation)
  int setMinute( int m); // set minute (after validation)
  int setSecond( int s); // set second (after validation)

  // get functions
  int getHour(); // return hour
  int getMinute(); // return minute
  int getSecond(); // return second

  void printUniversal(); // output time in universal-time format
  void printStandard(); // output time in standard-time format

 private:
  int hour; // 0 - 23 (24-hour clock format)
  int minute; // 0 - 59
  int second; // 0 - 59
}; // end class Time


// Time constructor initializes each data member to zero
Time::Time( int h, int m, int s ) {
  setTime( h, m, s ); // validate and set time
} // end Time constructor

// set new Time value using universal time
void Time::setTime( int h, int m, int s ) {
  if (setHour(h) != 1)
    cout << "wrong hour!";
  if (setMinute(m) != 1)
    cout << "wrong minute!";
  if (setSecond(s) != 1)
    cout << "wrong second!";
} // end function setTime

// set hour value
int Time::setHour( int h ) {
  if ( h >= 0 && h < 24 ) {
    hour = h;
    return 1;
  } else {
    return 0;
  }
} // end function setHour

// set minute value
int Time::setMinute( int m ) {
  if ( m >= 0 && m < 60 ) {
    minute = m;
    return 1;
  } else {
    return 0;
  }
} // end function setMinute

// set second value
int Time::setSecond( int s ) {
  if ( s >= 0 && s < 60 ) {
    second = s;
    return 1;
  } else {
    return 0;
  }
} // end function setSecond

// return hour value
int Time::getHour() {
  return hour;
} // end function getHour

// return minute value
int Time::getMinute() {
  return minute;
} // end function getMinute

// return second value
int Time::getSecond() {
  return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() {
  cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
       << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() {
  cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
       << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
       << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard

