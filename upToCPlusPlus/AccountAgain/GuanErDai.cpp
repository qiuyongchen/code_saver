#include "GuanErDai.h"
#include <iostream>
using namespace std;

GuanErDai::GuanErDai() {
  name_ = "";
}

GuanErDai::GuanErDai(const string& name, const string& dadName, double balance)
  :Account(dadName, balance) {
  name_ = name;
}

string GuanErDai::getName() const {
  return name_;
}
double GuanErDai::getBalance() const {
  return Account::getBalance();
}

void GuanErDai::setName(string name) {
  name_ = name;
}

void GuanErDai::setBalance(double balance) {
  Account::setBalance(balance);
}

 
