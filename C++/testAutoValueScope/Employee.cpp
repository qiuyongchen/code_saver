// Fig. 10.19: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "Employee.h" // Employee class definition
using namespace std;
// define and initialize static data member at global namespace scope
int Employee::count = 0; // cannot include keyword static
// define static member function that returns number of
// Employee objects instantiated (declared static in Employee.h)
int Employee::getCount()
{
return count;
} // end static function getCount
// constructor initi

Employee::Employee( const string &first, const string &last )
: firstName( first ), lastName( last )
{
++count; // increment static count of employees
cout << "Employee constructor for " << firstName
<< ' ' << lastName << " called." << endl;
} // end Employee constructor
// destructor deallocates dynamically allocated memory
Employee::~Employee()
{
cout << "~Employee() called for " << firstName
<< ' ' << lastName << endl;
--count; // decrement static count of employees
} // end ~Employee destructor

// return first name of employee
string Employee::getFirstName() const
{
return firstName; // return copy of first name
} // end function getFirstName
// return last name of employee
string Employee::getLastName() const
{
return lastName; // return copy of last name
} // end function getLastName
