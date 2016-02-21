// ex0314.cpp
// the main function.
#include <iostream>
#include <string>
using namespace std;

#include "Employee.h"

int main() {
  Employee emploOne;
  emploOne.setFirstName("wlxead");
  emploOne.setLastName("redleaf");
  emploOne.setMonthlySalary(500000);

  cout << "The yearly salary of " << emploOne.getFirstName()
       << emploOne.getLastName() << " is: " << emploOne.getMonthlySalary() * 12
       << endl;

  Employee emploTwo;
  emploTwo.setMonthlySalary(-3);
  emploTwo.setFirstName("Jobs");
  emploTwo.setLastName("OL");

  cout << "The yearly salary of " << emploTwo.getFirstName()
       << emploTwo.getLastName() << " is: " << emploTwo.getMonthlySalary() * 12
       << endl;

  emploOne.setMonthlySalary(emploOne.getMonthlySalary() * 1.1);
  emploTwo.setMonthlySalary(emploTwo.getMonthlySalary() * 1.1);

  cout << "The yearly salary of " << emploOne.getFirstName()
       << emploOne.getLastName() << " is: " << emploOne.getMonthlySalary() * 12
       << endl;

  cout << "The yearly salary of " << emploTwo.getFirstName()
       << emploTwo.getLastName() << " is: " << emploTwo.getMonthlySalary() * 12
       << endl;

  return 0;
}
