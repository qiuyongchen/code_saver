#include "Account.h"
#include <iostream>
using namespace std;

Account::Account() {
  next_ = NULL;
}

Account::Account(const string& name, double balance) {
  setName(name);
  setBalance(balance);
  next_ = NULL;
}

string Account::getName() const {
  return name_;
}

double Account::getBalance() const {
  return balance_;
}

Account* Account::getNext() const {
  return next_;
}

void Account::setName(const string& name) {
  name_ = name;
}

void Account::setBalance(double balance) {
  balance_ = balance;
}

void Account::setNext(Account* next) {
  next_ = next;
}
