#include "Account.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int Account::_total_account = 0;

int Account::get_total_account() {
  return _total_account;
}

Account::Account() {
  _id = 0;
  _balance = 0;
  _valid = false;
  _total_account++;
}

Account::~Account() {
  _total_account--;
}

int Account::id() const {
  return _id;
}

double Account::balance() const {
  return _balance;
}

bool Account::valid() const {
  return _valid;
}

string Account::profile() const {
  stringstream ss, ss1;
  string s, s1;
  ss << id();
  ss >> s;

  if (valid()) {
    s1 = "Y";
  } else {
    s1 = "N";
  }

  char c[100];
  snprintf(c, sizeof(c), "%.6f", balance());
  string cc;
  cc =c;
  string temp;
  temp += "ID:" + s + "\n" + "BALANCE:" + cc + "\n";
  temp += "VALID:" + s1 + "\n";
  return temp;
}

void Account::reset() {
  _balance = 0;
  _valid = false;
  _total_account = 0;
}

bool Account::deposit(const double &num) {
  _balance += num;
  return true;
}

bool Account::draw(const double &num) {

  if (num < _balance - 0.01) {
    _balance -= num;
    return true;
  } else {
    return false;
  }

}


