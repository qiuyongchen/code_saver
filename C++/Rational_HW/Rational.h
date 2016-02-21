#ifndef RATIONAL_H
#define RATIONAL_H
    
class Rational {
 public:
  Rational(int = 0, int = 1);
  Rational addition(const Rational &);
  Rational subtraction(const Rational &);
  Rational multiplication(const Rational &);
  Rational division(const Rational &);
  void printRational();
  void printRationalAsDouble();
 private:
  int numerator;
  int denominator;
  void reduction();
};
     
#endif
     

