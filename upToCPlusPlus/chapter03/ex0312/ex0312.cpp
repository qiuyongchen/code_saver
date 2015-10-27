// ex0312.cpp
#include <iostream>
#include "Account.h"

using namespace std;

int main() {
  Account accountOne(10);
  accountOne.credit(999);
  accountOne.debit(50);
  cout << accountOne.getBalance() << endl;

  Account accountTwo(-4);
  accountTwo.debit(500);
  cout << accountTwo.getBalance() << endl;

  return 0;
}
