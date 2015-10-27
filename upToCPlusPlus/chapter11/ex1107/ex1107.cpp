// Created by YongchenQiu.
// ex1107.cpp
// The main function.
#include "Array.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
  int r, c;
  cout << "Please input the row and the column of the array:" << endl;
  cin >> r >> c;

  Array a(r, c);

  cout << "Please input the elements of the array(one by one):" << endl;
  cin >> a;

  cout << "The array is shown below:" << endl;
  cout << a << endl;

  cout << "Now, we creat a new array b copying the last one." << endl;
  Array b(a);

  cout << "The new array b is shown below:" << endl;
  cout << b << endl;

  if (a == b)
    cout << "b is equal to a" << endl;

  if (a != b)
    cout << "b is not equal to a" << endl;

  cout << "The (1, 1) of b is " << b(1, 1) << endl;

  cout << "Now we change the element (1, 1) of b to 43" << endl;
  b(1, 1) = 43;

  cout << "The (1, 1) of b is " << b(1, 1) << endl;

  if (a == b)
    cout << "b is equal to a" << endl;

  if (a != b)
    cout << "b is not equal to a" << endl;

  cout << "b is:" << endl << b << endl;
  cout << "a is:" << endl << a << endl;

  cout << "Now we assign a to b" << endl;
  b = a;

  cout << "b is:" << endl << b << endl;
  cout << "a is:" << endl << a << endl;

  return 0;
}

