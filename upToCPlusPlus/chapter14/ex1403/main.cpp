// main.cpp.
// function template.
// Selection sort with pass-by-reference. This program puts values into an
// array, sorts them into ascending order and prints the resulting array.

#include <iostream>
#include <iomanip>
using namespace std;

template<typename S>
void selectionSort(S * const, const int); // prototype

template<typename S> 
void swap(S * const, S * const); // prototype

int main() {
  // declare the array.
  int in[5];
  float fl[5];

  // chase the 'int' array.
  cout << "input the elements of the 'int' array(must be 5 elements!):\n";
  for (int i = 0; i < 5; i++) {
    cin >> in[i];
  }
  cout << "Data items in original order:\n";
  for (int i = 0; i < 5; i++) {
    cout << setw(6) << in[i];
  }
  cout << endl;
  selectionSort(in, 5);
  cout << "Data items in ascending order:\n";
  for (int i = 0; i < 5; i++) {
    cout << setw(6) << in[i];
  }
  cout << endl;

  // guy the 'float' array.
  cout << "input the elements of the 'float' array(must be 5 elements!):\n";
  for (int i = 0; i < 5; i++) {
    cin >> fl[i];
  }
  cout << "Data items in original order:\n";
  for (int i = 0; i < 5; i++) {
    cout << setw(6) << fl[i];
  }
  cout << endl;
  selectionSort(fl, 5);
  cout << "Data items in ascending order:\n";
  for (int i = 0; i < 5; i++) {
    cout << setw(6) << fl[i];
  }
  cout << endl;

  /*
  const int arraySize = 10;
  int a[ arraySize ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
  cout << "Data items in original order\n";
  for (int i = 0; i < arraySize; ++i)
    cout << setw( 4 ) << a[ i ];
  selectionSort( a, arraySize );  // sort the array
  cout << "\nData items in ascending order\n";
  for (int j = 0; j < arraySize; ++j)
    cout << setw( 4 ) << a[ j ];
  cout << endl;
  */

  return 0;
} // end main

// function to sort an array
template<typename S> 
void selectionSort(S * const array, const int size) {
  int smallest; // index of smallest element
  // loop over size - 1 elements
  for (int i = 0; i < size - 1; ++i) {
    smallest = i; // first index of remaining array
  // loop to find index of smallest element
    for (int index = i + 1; index < size; ++index)
      if (array[ index ] < array[ smallest ])
	smallest = index;
    swap( &array[ i ], &array[ smallest ] );
  }  // end if
} // end function selectionSort

// swap values at memory locations to which
// element1Ptr and element2Ptr point
template<typename S> 
void swap( S * const element1Ptr, S * const element2Ptr ) {
  S hold = *element1Ptr;
  *element1Ptr = *element2Ptr;
  *element2Ptr = hold;
} // end function swap
