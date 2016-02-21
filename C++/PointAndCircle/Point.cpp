#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int xx, int yy) {
  setPoint(xx, yy);
}

void Point::setPoint(int xx, int yy) {
  x = xx;
  y = yy;
}

int Point::getX() const {
  return x;
}

int Point::getY() const {
  return y;
}

void Point::print() const {
  cout << "This Point is [" << getX() << ", " << getY() << "]" << endl;
}
