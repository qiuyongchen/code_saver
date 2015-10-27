// Created by YongchenQiu
// ex1001.cpp
#include "Date.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
  Date dOne('a');
  Date dTwo("June", "01,2000");
  Date dThree(34, 2001);
  Date dFourth("06/12/03", 1);

  dOne.print();
  cout << endl;

  dTwo.print();
  cout << endl;

  dThree.print();
  cout << endl;

  dFourth.print();
  cout <<endl;

  return 0;
}
