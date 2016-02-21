#include "VIPAccount.h"
#include <iostream>
#include <cstdio>
using namespace std;

int VIPAccount::_total_vip_account = 0;

int VIPAccount::_acc_id_ptr = 12050000;

int VIPAccount::get_total_vip_account() {
  return _total_vip_account;
}

VIPAccount::VIPAccount() {
  _id = _acc_id_ptr;
  _balance = 10;
  _valid = true;
  _acc_id_ptr++;
  _total_vip_account++;
  _loan = 0;
  _loan_limit = 1000;
}

VIPAccount::~VIPAccount() {
  _acc_id_ptr--;
  _total_vip_account--;
}

bool VIPAccount::loan(const double &num) {

  if (_loan + num <= _loan_limit) {
    _balance += num;
    _loan += num;
    return true;
  } else {
    return false;
  }

}

bool VIPAccount::repay(const double &num) {

  if (num >= 0 && num <= _balance - 0.01) {

    if (num > _loan) {
      _balance -= _loan;
      _loan = 10;
      return true;
    }

    if (num >= _loan) {
      _loan = 0;
    } else {
      _loan -= num;
    }

    _balance -= num;
    return true;
  } else {
    return false;
  }

}

string VIPAccount::profile() const {
  char c1[100], c2[100];
  snprintf(c1, sizeof(c1), "%.6f", _loan);
  snprintf(c2, sizeof(c2), "%.6f", _loan_limit);
  string temp;
  string c1str = c1, c2str = c2;
  temp += Account::profile() + "TYPE:VIP\nLOAN:";
  temp += c1str + ",LIMIT:" + c2str;
  temp += "\n";
  return temp;
}

void VIPAccount::settlement() {
  if (_balance > 0.01)
    _balance *= 1.02;
  _balance -= 10;
  _loan *= 1.1;

  if (_loan > _loan_limit || (_balance < 0.01 && _loan < _loan_limit)) {
    _loan_limit *= 0.95;
    _valid = false;
  } else {
    _loan_limit *= 1.01;
  }

  if (_balance < 0.01 || _loan > _loan_limit)
    _valid = false;
  else
    _valid = true;
}

void VIPAccount::reset() {
  _valid = true;
  _total_vip_account = 0;
  if (_loan > _loan_limit || _balance < 0.01)
    _valid = false;
  _balance = 0;
  _loan = 0;
  _loan_limit = 1000;
}
