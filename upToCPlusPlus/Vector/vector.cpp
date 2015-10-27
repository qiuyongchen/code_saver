#include "vector.h"
#include <iostream>
#include <string>
using namespace std;

template <typename sT>
ostream & operator<< (ostream &out, const Vector<sT> &v) {
  // no full no out.
  if (!v.empty()) {
    out << v.data[0];
    // for the " ".
    for (int i = 1; i < v.size(); i++) {
      out << " ";
      out << v.data[i];
    }
  }

  out << endl;
  return out;
}

// the empty constructor.
template <typename S>
Vector<S>::Vector(int s) {
  maxSize = s;
  _size = 0;
  if (maxSize > 0) {
    data = new S[maxSize];
  }
}

// the destructor.
template <typename S>
Vector<S>::~Vector() {
  maxSize = 0;
  _size = 0;
  delete []data;
}

// the copy constructor.
template <typename S>
Vector<S>::Vector(const Vector<S> & V) {
  maxSize = V.maxSize;
  _size = V._size;
  if (maxSize > 0) {
    data = new S[maxSize];
  }

  // copy the element.
  for (int i = 0; i < size(); i++) {
    data[i] = V.data[i];
  }

}

template <typename S>
int Vector<S>::size() const {
  return _size;
}

template <typename S>
bool Vector<S>::empty() const {
  return size() == 0;
}

template <typename S>
void Vector<S>::clear() {

  while (!empty()) {
    pop_back();
  }
  maxSize = 0;
  delete []data;
}

template <typename S>
void Vector<S>::push_back(S ele) {
  // if there is need, then update the 'this' object.
  if (size() == maxSize) {
    Vector<S> temp(*this);  // instant a temp object.
    maxSize *= 2;  // there is no change for '_size'.
    delete []data; // avoid memory leak.
    data = new S[maxSize];  // new array.

    // copy the element.
    for (int i = 0; i < temp.size(); i++) {
      data[i] = temp.data[i];
    }
  }

  // inset the element.
  data[size()] = ele;
  _size++;
}

template <typename S>
void Vector<S>::pop_back() {
  if (!empty()) {
    _size--;
    data[_size] = 0;
  }
}

template <typename S>
S & Vector<S>::operator[] (int index) {
  return data[index];
}

template <typename S>
Vector<S> & Vector<S>::operator= (const Vector<S> & v) {
  clear();

  maxSize = v.maxSize;
  _size = v._size;
  data = new S[maxSize];

  // copy the element.
  for (int i = 0; i < size(); i++) {
    data[i] = v.data[i];
  }

  return *this;
}
