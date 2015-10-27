#include <iostream>
#include <iomanip>
#include "Rational.h"
using namespace std;

Rational::Rational(int num, int den) {
  numerator = num;
  denominator = den;

  int temp;
  if (num > den) {
    temp = num;
    num = den;
    den = temp;
  }

  while (num % den != 0) {
    temp = num % den;
    num = den;
    den = temp;
  }

  temp = den;

  denominator /= temp;
  numerator /= temp;

}

Rational Rational::addition(const Rational &wlxead) {
  Rational newOne;
  newOne.numerator = numerator * wlxead.denominator;
  newOne.numerator += denominator * wlxead.numerator;
  newOne.denominator = denominator * wlxead.denominator;
  newOne.reduction();
  return newOne;
}

Rational Rational::subtraction(const Rational &wlxead) {
  Rational newOne;
  newOne.numerator = numerator * wlxead.denominator;
  newOne.numerator -= denominator * wlxead.numerator;
  newOne.denominator = denominator * wlxead.denominator;
  newOne.reduction();
  return newOne;
}

Rational Rational::multiplication(const Rational &wlxead) {
  Rational newOne;
  newOne.numerator = numerator * wlxead.numerator;
  newOne.denominator = denominator * wlxead.denominator;
  newOne.reduction();
  return newOne;
}

Rational Rational::division(const Rational &wlxead) {
  Rational newOne;
  newOne.numerator = numerator * wlxead.denominator;
  newOne.denominator = denominator * wlxead.numerator;
  newOne.reduction();
  return newOne;
}

void Rational::printRational() {
  cout << numerator << '/' << denominator;
}

void Rational::printRationalAsDouble() {
  double d;
  d = static_cast<double>(numerator)/denominator;
  cout << d;
}

void Rational::reduction() {
  int temp;
  int denRes = denominator;
  int numRes = numerator;

  if (numRes > denRes) {
    temp = numRes;
    numRes = denRes;
    denRes = temp;
  }

  while (numRes % denRes != 0) {
    temp = numRes % denRes;
    numRes = denRes;
    denRes = temp;
  }

  temp = denRes;

  denominator /= temp;
  numerator /= temp;

}
