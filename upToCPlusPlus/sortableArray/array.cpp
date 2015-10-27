#include "array.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
SortableArray <T>::SortableArray(int s) {
  maxSize = s;
  array = new T[maxSize];
  size = 0;
}

template <typename T>
SortableArray <T>::~SortableArray() {
  delete []array;
}

template <typename T>
void SortableArray <T>::pushBack(T a) {

  if (size == maxSize) {
    cout << "Already full!" << endl;
  } else {
    array[size] = a;
    size++;
  }

}

template <typename T>
void SortableArray <T>::sort() {

  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {

      if (array[i] > array[j]) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }

    }
  }

}

template <typename T>
void SortableArray <T>::printArray() {
  int flag = 0;
  for (int i = 0; i < size; i++) {
    if (flag) cout << " ";
    cout << array[i];
    flag = 1;
  }
  cout << endl;
}
