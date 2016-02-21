#include "Complex.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &o, const Complex &a) {
  o << a.real << "+" << a.imag << "i" << endl;
  return o;
}

Complex::Complex(double x, double y) {
  SetReal(x);
  SetImag(y);
}

Complex::Complex(const Complex &a) {
  SetReal(a.real);
  SetImag(a.imag);
}

Complex::~Complex() {
}

Complex &Complex::operator= (const Complex &a) {
  SetReal(a.real);
  SetImag(a.imag);
  return (*this);
}

bool Complex::operator== (const Complex &a) const {
  return real == a.real && imag == a.imag;
}

bool Complex::operator!= (const Complex &a) const {
  return !((*this) == a);
}

Complex Complex::operator+ (const Complex &a) const {
  Complex temp(real + a.real, imag + a.imag);
  return temp;
}

Complex Complex::operator- (const Complex &a) const {
  Complex temp(real - a.real, imag - a.imag);
  return temp;

}

Complex Complex::operator* (const Complex &a) const {
  Complex temp(real * a.real - imag * a.imag, real * a.imag + imag * a.real);
  return temp;
}

Complex Complex::operator/ (const Complex &a) const {
  double r = a.real * a.real + a.imag * a.imag;
  Complex temp = (*this) * Complex(a.real, -a.imag);
  temp.real /= r;
  temp.imag /= r;
  return temp;
}

void Complex::operator+= (const Complex &a) {
  (*this) = (*this) + a;
}

void Complex::operator-= (const Complex &a) {
  (*this) = (*this) - a;
}

void Complex::operator*= (const Complex &a) {
  (*this) = (*this) * a;
}

void Complex::operator/= (const Complex &a) {
  (*this) = (*this) / a;
}


