// Arithmetic.h
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Arithmetic {
 public:
  Arithmetic(T a, T b);
  T addition();
  T subtraction();
  T multiplication();
  T division();
 private:
  T a;
  T b;
};
