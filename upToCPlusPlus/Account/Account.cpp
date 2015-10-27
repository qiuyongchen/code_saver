#include "Account.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int Account::count_ = 0;

int Account::getCount() {
  return count_;
}

Account::Account(const string& name) {
  name_ = name;
  balance_ = 0;
  log_ = "";
  log_ += "Create an account ";
  log_ += getName();
  log_ += "\n";
  count_++;
}

Account::Account(const string& name, int balance) {
  name_ = name;
  balance_ = balance;
  log_ = "";
  log_ += "Create an account ";
  log_ += getName();
  log_ += "\n";
  count_++;
}

Account::~Account() {
  count_--;
}

void Account::deposit(int amount) {

  if (amount < 0) {
    cout << "Error operation!\n";
    log_ += "Error operation!\n";
  } else {
    balance_ += amount;
    log_ += "Deposit " + intToStr(amount) + " yuan\n";
  }

}

bool Account::withdraw(int amount) {

  if (amount < 0) {
    cout << "Error operation!\n";
    log_ += "Error operation!\n";
    return false;
  } else if (amount > balance_) {
    cout << "You don't have enough money!\n";
    log_ += "Error operation!\n";
    return false;
  } else {
    balance_ -= amount;
    log_ += "Withdraw " + intToStr(amount) + " yuan\n";
    return true;
  }
  return true;
}

string Account::intToStr(int target) {
  stringstream ss;
  string s;
  ss << target;
  ss >> s;
  return s;

}
