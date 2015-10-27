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
}; // end class Time


// Time constructor initializes each data member to zero
Time::Time( int h, int m, int s ) {
  setTime( h, m, s ); // validate and set time
} // end Time constructor

// set new Time value using universal time
void Time::setTime( int h, int m, int s ) {
  setHour( h ); // set private field hour
  setMinute( m ); // set private field minute
  setSecond( s ); // set private field second
} // end function setTime

// set hour value
void Time::setHour( int h ) {
  if ( h >= 0 && h < 24 )
    hour = h;
  else
    throw invalid_argument( "hour must be 0-23" );
} // end function setHour

// set minute value
void Time::setMinute( int m ) {
  if ( m >= 0 && m < 60 )
    minute = m;
  else
    throw invalid_argument( "minute must be 0-59" );
} // end function setMinute

// set second value
void Time::setSecond( int s ) {
  if ( s >= 0 && s < 60 )
    second = s;
  else
    throw invalid_argument( "second must be 0-59" );
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

// increments the time store in a Tiem object by one second
void Time::tick( void ) {

  if ( hour == 23 && minute == 59 && second == 59 ) {
    setTime( 0, 0, 0 );
  } else if ( minute == 59 && second == 59 ) {
    setTime( getHour() + 1, 0, 0 );
  } else if ( second == 59 ) {
    setTime( getHour(), getMinute() + 1, 0 );
  } else {
    setTime( getHour(), getMinute(), getSecond() + 1 );
  }

}
