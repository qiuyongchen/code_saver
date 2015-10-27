#include "FuErDai.h"
#include <iostream>
using namespace std;

FuErDai::FuErDai() {
  name_ = "";
}

FuErDai::FuErDai(const string& name, const string& dadName, double balance)
  :Account(dadName, balance) {
  name_ = name;
}

string FuErDai::getName() const {
  return name_;
}
double FuErDai::getBalance() const {
  return Account::getBalance();
}

void FuErDai::setName(string name) {
  name_ = name;
}

void FuErDai::setBalance(double balance) {
  Account::setBalance(balance);
}

 
