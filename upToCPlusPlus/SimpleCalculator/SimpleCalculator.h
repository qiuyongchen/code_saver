#include <iostream>
#include <stdexcept>

class SimpleCalculator {
 public:
  SimpleCalculator();
  void add(double a, double b);
  void subtract(double a, double b);
  void multiply(double a, double b);
  void divide(double a, double b);
  double getAnswer() const;
 private:
  double answer;
};

SimpleCalculator::SimpleCalculator() {
  answer = 0;
}
void SimpleCalculator::add(double a, double b) {
  answer = a + b;
}

void SimpleCalculator::subtract(double a, double b) {
  answer = a - b;
}

void SimpleCalculator::multiply(double a, double b) {
  answer = a * b;
}

void SimpleCalculator::divide(double a, double b) {
  answer = a / b;
}

double SimpleCalculator::getAnswer() const {
  return answer;
}
