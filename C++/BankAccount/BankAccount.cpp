#include "BankAccount.h"
#include <iostream>
#include <string>

using namespace std;

void BankAccount::reset() {
  setBalance(0);
  setName("NONAME");
}

int BankAccount::getBalance() const {
  return balance;
}

void BankAccount::setBalance(int newBalance) {

  if (newBalance < 0) {
    balance = 0;
  } else if (newBalance > 200000) {
    balance = 200000;
  } else {
    balance = newBalance;
  }

}

string BankAccount::getName() const {
  return name;
}

void BankAccount::setName(string newName) {

  if (newName == "") {
    name = "INVALID";
  } else {
    name = newName;
  }

}
