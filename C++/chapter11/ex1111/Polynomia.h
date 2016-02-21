// Polynomia.h
// Created by YongchenQiu.
// The declaration and implement of class Polynomia.
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Polynomia {
 public:
  Polynomia();
  ~Polynomia();

  void set(int coe, int exp);
  int get(int exp);

  Polynomia operator+(Polynomia &other);
  Polynomia operator-(Polynomia &other);
  Polynomia operator*(Polynomia &other);
  bool operator=(Polynomia other);
  bool operator+=(Polynomia &other);
  bool operator-=(Polynomia &other);
  bool operator*=(Polynomia &other);

 private:
  int term[5];
};

Polynomia::Polynomia() {

  for (int i = 0; i < 5; i++) {
    term[i] = 0;
  }

}

// the deconstructor of class Polynomia
Polynomia::~Polynomia() {

}

void Polynomia::set(int coe, int exp) {

  if (exp < 0 || exp > 5)
    throw invalid_argument ("exponent invalid");

  term[exp] = coe;
}

int Polynomia::get(int exp) {
  return term[exp];
}

Polynomia Polynomia::operator+(Polynomia &other) {
  Polynomia tempPoly;

  for (int i = 0; i < 5; i++)
    tempPoly.set((term[i] + other.get(i)), i);


  return tempPoly;
}

Polynomia Polynomia::operator-(Polynomia &other) {
  Polynomia tempPoly;

  for (int i = 0; i < 5; i++)
    tempPoly.set((term[i] - other.get(i)), i);

  return tempPoly;
}


Polynomia Polynomia::operator*(Polynomia &other) {
  Polynomia tempPoly;

  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++) {
      tempPoly.set((tempPoly.get(i + j) + term[i] * other.term[j]), (i + j));
    }

  }

  return tempPoly;

}

bool Polynomia::operator=(Polynomia other) {

  for (int i = 0; i < 5; i++)
    term[i] = other.get(i);

  return true;
}

bool Polynomia::operator+=(Polynomia &other) {
  *(this) = (*this) + other;
  return true;
}

bool Polynomia::operator-=(Polynomia &other) {
  *(this) = (*this) - other;
  return true;
}

bool Polynomia::operator*=(Polynomia &other) {
  *(this) = (*this) * other;
  return true;

}
