#include <iostream>
#include "Bank.h"
using namespace std;

void Bank::do_settlement() {

  for (int i = 0; i < _list.size();i++) {
    _list.at(i)->settlement();
  }

}

void Bank::insert(Account* g) {
  _list.push_back(g);
}
