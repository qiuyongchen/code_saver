#include <iostream>
#include "Employee.h" // Employee class definition
using namespace std;
int main()
{
// no objects exist; use class name
// operator to access static member
cout << "Number of employees before"
      << Employee::getCount() << endl;
// use class name
// the following scope creates and destroys
// Employee objects before main terminates
//{
Employee e1( "Susan", "Baker" );
Employee e2( "Robert", "Jones" );

cout << "Number of employees after objects are instantiated is "
<< Employee::getCount() ;

cout << "\n\nEmployee 1: "
<< e1.getFirstName() << " " << e1.getLastName()
<< "\nEmployee 2: "
<< e2.getFirstName() << " " << e2.getLastName() << "\n\n";
//} // end nested scope in main
// no objects exist, so call static member function getCount again
// using the class name and the scope resolution operator
cout << "\nNumber of employees after objects are deleted is "
<< Employee::getCount() << endl;
} // end main
