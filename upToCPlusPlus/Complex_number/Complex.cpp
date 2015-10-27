#include <iostream>
using namespace std;

#include "Complex.h"

Complex::Complex(void) {

}

Complex::Complex(double real_wlxead, double imaginary_wlxead) {
  realPart = real_wlxead;
  imaginaryPart = imaginary_wlxead;
}

Complex Complex::add( const Complex &right ) {
  Complex newOne;
  newOne.realPart = right.realPart + realPart;
  newOne.imaginaryPart = right.imaginaryPart + imaginaryPart;
  return newOne;
}

Complex Complex::subtract( const Complex &right ) {
  Complex newOne;
  newOne.realPart = right.realPart - realPart;
  newOne.imaginaryPart = right.imaginaryPart - imaginaryPart;
  return newOne;
}

void Complex::printComplex() {
 cout << '(' << realPart << ", " << imaginaryPart << ')';
}

void Complex::setComplexNumber(double wlxead, double redleaf) {
 realPart = wlxead;
 imaginaryPart = redleaf;
}
