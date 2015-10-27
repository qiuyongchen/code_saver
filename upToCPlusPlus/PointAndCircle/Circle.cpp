#include "Circle.h"
#include <iostream>
#define PI 3.14159
using namespace std;


Circle::Circle(double r, int x, int y):Point(x, y) {
  setRadius(r);
}

void Circle::setRadius(double r) {
  if (r > 0)
    radius = r;
  else
    radius = 0;
}

double Circle::getRadius() const {
  return radius;
}

double Circle::area() const {
  return PI * radius * radius;
}

void Circle::print() const {
  cout << "The center of Circle is [" << getX() << ", "
       << getY() << "]" << endl
       << "The radius of Circle is " << getRadius() << endl;
}

