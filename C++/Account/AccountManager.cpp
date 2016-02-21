#include "AccountManager.h"
#include <iostream>
#include <string>
using namespace std;

double AccountManager::interest_rate_ = 0.05;

void AccountManager::createAccount(const string& name) {
  int con = Account::getCount();
  if (Account::getCount() < 10) {
    accounts_[con] = new Account(name);
  }
}

void AccountManager::createAccount(const string& name, int balance) {
  int con = Account::getCount();
  if (Account::getCount() < 10) {
    accounts_[con] = new Account(name, balance);
  }
}

void AccountManager::caculateInterest() {

  if (Account::getCount() == 0) {
    cout << "Not any account!" << endl;
  }

  for (int i = 0; i < Account::getCount(); i++) {
    accounts_[i]->deposit(accounts_[i]-> getBalance() * interest_rate_);
  }
}

Account* AccountManager::getAccount(int position) {

  if (position < 0 || position >= Account::getCount()) {
    cout << "Error operation!" << endl;
    return NULL;
  }

  return accounts_[position];
}

AccountManager::~AccountManager() {
  int cou = Account::getCount();
  for (int i = 0; i < cou; i++) {
    delete accounts_[i];
  }

}

