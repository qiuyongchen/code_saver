// Created by YongchenQiu.
// Array.h
// The declaration and implement of Array class.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class Array {
  // overload << and >> for Array class.
  friend ostream &operator<<(ostream &o, const Array &a);
  friend istream &operator>>(istream &i, Array &a);
 public:
  Array(int i = 100, int j = 100);
  Array(const Array &a);
  ~Array();

  Array &operator= (const Array &a);
  bool operator== (const Array &a) const;
  bool operator!= (const Array &a) const;

  // subscript operator for non-const object returns a lvalue.
  int &operator() (const int x, const int y);

  // subscript operator for const object returns a rvalue.
  int operator() (const int x, const int y) const;

 private:
  int arrayRow;
  int arrayColumn;
  int *arrayPtr;
};


// initialization of the Array object.
Array::Array(int i, int j) {

  // check the size of the array.
  if (i > 0 && j > 0) {
    arrayRow = i;
    arrayColumn = j;
  } else {
    throw invalid_argument("Array size should be greater than 0");
  }

  // malloc memory for the arrayPtr.
  arrayPtr = new int[i * j];

  for (int i = 0; i < arrayRow * arrayColumn; i++)
    arrayPtr[i] = 0;

}

// copy initialize.
Array::Array(const Array &a) {
  arrayRow = a.arrayRow;
  arrayColumn = a.arrayColumn;

  arrayPtr = new int[a.arrayRow * a.arrayColumn];

  for (int i = 0; i < a.arrayRow * a.arrayColumn; i++)
    arrayPtr[i] = a.arrayPtr[i];

}

Array::~Array() {
  delete []arrayPtr;
}

Array &Array::operator=(const Array &a) {

  if (arrayRow != a.arrayRow || arrayColumn != a.arrayColumn)
    throw invalid_argument ("The two array are not the same size!");

  for (int i = 0; i < a.arrayRow * a.arrayColumn; i++)
    arrayPtr[i] = a.arrayPtr[i];

  return *this;
}

bool Array::operator==(const Array &a) const {

  if (arrayRow != a.arrayRow || arrayColumn != a.arrayColumn)
    return false;

  for (int i = 0; i < a.arrayRow * a.arrayColumn; i++) {

    if (arrayPtr[i] != a.arrayPtr[i])
      return false;

  }

  return true;
}

bool Array::operator!=(const Array &a) const {
  return !(*this == a);
}

// subscript operator for non-const object returns a lvalue.
int &Array::operator()(const int x, const int y) {

  if (x < 0 || x >= arrayRow)
    throw invalid_argument ("the row is invalid!");

  if (y < 0 || y >= arrayColumn)
    throw invalid_argument ("the column is invalid!");

  return arrayPtr[(x - 1) * arrayRow + y - 1];

}

// subscript operator for const object returns a rvalue.
int Array::operator()(const int x, const int y) const {

  if (x < 0 || x >= arrayRow)
    throw invalid_argument ("the row is invalid!");

  if (y < 0 || y >= arrayColumn)
    throw invalid_argument ("the column is invalid!");

  return arrayPtr[(x - 1) * arrayRow + y - 1];

}

ostream &operator<<(ostream &out, const Array &a) {

  for (int i = 0; i <= a.arrayColumn; i++) {
    out << "***";
  }

  out << endl << "  ";

  for (int i = 0; i < a.arrayRow * a.arrayColumn; i++) {
    out << a.arrayPtr[i] << "  ";

    if (((i + 1) % a.arrayColumn == 0) && i < (a.arrayRow * a.arrayColumn - 1))
      out << endl << "  ";

  }

  out << endl;

  for (int i = 0; i <= a.arrayColumn; i++) {
    out << "***";
  }

  return out;

}

istream &operator>> (istream &in, Array &a) {

  for (int i = 0; i < a.arrayRow * a.arrayColumn; i++) {
    in >> a.arrayPtr[i];
  }

  return in;

}
