#include "Student.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
using namespace std;

int Student::numStudents = 0;

Student::Student(const char *nameStr) {
  name = new char[1000];
  grades = new int[1000];
  idNum = 0;
  numGrades = 0;
  int i;

  numStudents++;
  idNum = numStudents;

  cout << "A student has been added\n";
  for (i = 0; i < strlen(nameStr); i++) {
    name[i] = nameStr[i];
  }

  name[i] = '\0';
}

Student::~Student() {
  delete []name;
  delete []grades;
  cout << "Student " << idNum <<" has been deleted\n";
}

void Student::displayGrades() const {
  cout << "Here are the grades for " << name << endl;
  for (int i = 0; i < numGrades; i++)
    cout << setw(5) << grades[i];
  cout << endl << endl;
}

Student &Student::addGrade(int grade) {
  grades[numGrades] = grade;
  numGrades++;
  return *this;
}

int Student::getNumStudents() {
  return numStudents;
}
