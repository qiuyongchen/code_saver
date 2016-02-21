#include "stack.h"
#include <iostream>
#include <string>
using namespace std;


Stack::Stack() {
  for (int i = 0; i < 200; i++) {
    base[i] = -1;
  }
  size = 0;
}

void Stack::push(char c) {
  base[size] = c;
  size++;
}

char Stack::pop() {
  char c;
  c = base[size - 1];
  size--;
  return c;
}

char Stack::top() const {
  return base[size - 1];
}

bool Stack::isEmpty() const {
  if (size == 0)
    return true;
  else
    return false;
}

void Stack::clear() {
  for (int i = 0; i < 200; i++) {
    base[i] = -1;
  }
  size = 0;
}

int Stack::getSize() const {
  return size;
}
