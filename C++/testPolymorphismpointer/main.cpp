#include "me.h"
#include <iostream>
using namespace std;

int main() {
  me meOne;
  me *mePtr;
  meOne.print();

  you youOne;
  you *youPtr;
  youOne.print();

  // when we call the print() function, we call the version from the base class
  // because it depends on the pointer, not on the object it point to,
  // it is a little interesting? I don't know.
  // mePtr = &youOne;
  // mePtr->print();

  // we can not assign the address of base class to derive class pointer,
  // because base class is not a derive class( though a derive class is a base
  // class.
  // youPtr = &meOne;
  // youPtr->print();

  // derived-class member-function calls via base-class pointers, and it is
  // wrong.
  // mePtr->printPower();

  // After we declare the print() in both class me and class you,
  // we can invokes the print() of the class you through the pointer of
  // the class me.
  mePtr = &youOne;
  mePtr->print();

  return 0;
}
