// Account.h
// Declaration of the Account class
#include <iostream>
using namespace std;

class Account {
 public:
  Account(int balan = 0);
  void credit(int add);
  void debit(int del);
  int getBalance() const;

 private:
  int account;
};

Account::Account(int balan) {

  if (balan < 0) {
    account = 0;
    cout << "The initial balance was invalid" << endl;
  } else {
    account = balan;
  }

}

void Account::credit(int add) {
  account += add;
}

void Account::debit(int del) {

  if (del > account) {
    cout << "Debit amount exceeded account balance" << endl;
  } else {
    account -= del;
  }

}

int Account::getBalance() const {
  return account;
}
