// Employee.h
// Created by qiuyongchen.
#include <iostream>
#include <string>
using namespace std;

class Employee {
 public:
  Employee();
  void setFirstName(string firName);
  string getFirstName() const;
  void setLastName(string lasName);
  string getLastName() const;
  void setMonthlySalary(int monSala);
  int getMonthlySalary() const;
 private:
  string firstName;
  string lastName;
  int monthlySalary;
};

// The constructor of the Employee class.
Employee::Employee() {
  setFirstName("");
  setLastName("");
  setMonthlySalary(0);
}

// Set the first name.
void Employee::setFirstName(string firName) {
  firstName = firName;
}

string Employee::getFirstName() const {
  return firstName;
}

// Set the last name.
void Employee::setLastName(string lasName) {
  lastName = lasName;
}

string Employee::getLastName() const {
  return lastName;
}

// Set the monthly salary.
// If monSala < 0, then monthly salary is set to 0.
void Employee::setMonthlySalary(int monSala) {

  if (monSala < 0) {
    monthlySalary = 0;
  } else {
    monthlySalary = monSala;
  }

}

int Employee::getMonthlySalary() const {
  return monthlySalary;
}
