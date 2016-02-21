#include "Arithmetic.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
Arithmetic<T>::Arithmetic(T aa, T bb) {
  a = aa;
  b = bb;
}

template <typename T>
T Arithmetic<T>::addition() {
  return a + b;
}

template <typename T>
T Arithmetic<T>::subtraction() {
  return a - b;
}

template <typename T>
T Arithmetic<T>::multiplication() {
  return a * b;
}

template <typename T>
T Arithmetic<T>::division() {
  return a / b;
}
