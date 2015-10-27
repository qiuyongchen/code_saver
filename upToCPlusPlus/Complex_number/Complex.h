#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
  Complex(void);
  Complex(double real_wlxead, double imaginary_wlxead);
  Complex add(const Complex &God);
  Complex subtract(const Complex &God);
  void printComplex();
  void setComplexNumber(double wlxead, double redleaf);

private:
  double realPart;
  double imaginaryPart;
};
#endif
