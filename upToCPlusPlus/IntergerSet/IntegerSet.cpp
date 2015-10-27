#include "IntegerSet.h"
#include <iostream>
#include <iomanip>
using namespace std;

IntegerSet::IntegerSet(int s[], int l) {
  emptySet();

  for (int i = 0; i < l; i++) {

    if (validEntry(s[i]))
      insertElement(s[i]);
    else
      cerr << "Invalid Element\n";

  }

}

IntegerSet IntegerSet::unionOfSets(const IntegerSet &b) {
  IntegerSet c;

  for (int i = 0; i < 101; i++) {

    if (set[i] == 1 || b.set[i] == 1)
      c.set[i] = 1;

  }

  return c;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &b) {
  IntegerSet c;

  for (int i = 0; i < 101; i++) {

    if (set[i] == 1 && b.set[i] == 1)
      c.set[i] = 1;

  }

  return c;
}

void IntegerSet::emptySet() {

  for (int i = 0; i < 101; i++) {
    set[i] = 0;
  }

}

void IntegerSet::insertElement(int element) {
  set[element] = 1;
}

void IntegerSet::deleteElement(int element) {
  set[element] = 0;
}

bool IntegerSet::isEqualTo(const IntegerSet& b) const {
  bool iflag = true;

  for (int i = 0; i < 101; i++) {

    if (set[i] != b.set[i])
      iflag = false;

  }

  return iflag;
}


