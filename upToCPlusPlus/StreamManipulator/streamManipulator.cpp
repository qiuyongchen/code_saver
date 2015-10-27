#include "streamManipulator.h"
#include <iostream>
using namespace std;

void StreamManipulator::printInPrecision(double y, int x) {
  cout << dec << fixed << "Rounded to " << x << " digit(s) is ";
  cout << setprecision(x) << y << endl;
}

void StreamManipulator::convertFahrenToCelsis(int x) {
  cout << fixed << setprecision(3) << ((x -32) / 1.8) << endl;
}
