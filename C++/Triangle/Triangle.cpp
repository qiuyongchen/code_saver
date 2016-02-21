#include "Triangle.h"
#include <iostream>
#include <typeinfo>
#include <cmath>
using namespace std;

Triangle::Triangle() {
  cout << "Construct " << "Triangle" << endl;
}

void Triangle::set(int aa, int bb, int cc) {
  a = aa;
  b = bb;
  c = cc;
}

double Triangle::area() const {
  if ((*this).check()) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
  } else {return 0;
  }
}

void Triangle::print() const {
  if (check()) {
    cout << "It is Triangle" <<  "0-0\n";
  } else {
    cout << "It is not Triangle" <<  "=-=\n";
  }
}

bool Triangle::check() const {
  return (a + b > c) && (b + c > a) && (a + c > b);
}

IsoscelesTriangle::IsoscelesTriangle() {
  cout << "Construct " << "IsoscelesTriangle" << endl;
}

bool IsoscelesTriangle::check() const {
  return (Triangle::check() && (a == b || b == c || a == c));
}

void IsoscelesTriangle::print() const {
  if (check()) {
    cout << "It is IsoscelesTriangle" <<  "0-0\n";
  } else {
    cout << "It is not IsoscelesTriangle" <<  "=-=\n";
  }
}

RightTriangle::RightTriangle() {
  cout << "Construct " << "RightTriangle" << endl;
}

bool RightTriangle::check() const {
  return (Triangle::check() && (a * a + b * b == c * c || a * a + c * c
           == b * b || b * b + c * c == a * a));
}

void RightTriangle::print() const {
  if (check()) {
    cout << "It is RightTriangle" <<  "0-0\n";
  } else {
    cout << "It is not RightTriangle" <<  "=-=\n";
  }
}

IsoscelesRightTriangle::IsoscelesRightTriangle() {
  cout << "Construct " << "IsoscelesRightTriangle" << endl;
}

bool IsoscelesRightTriangle::check() const {
  return (IsoscelesTriangle::check() && RightTriangle::check());
}

void IsoscelesRightTriangle::print() const {
  if (check()) {
    cout << "It is IsoscelesRightTriangle" <<  "0-0\n";
  } else {
    cout << "It is not IsoscelesRightTriangle" <<  "=-=\n";
  }
}
