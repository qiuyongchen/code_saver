#include <iostream>
using namespace std;

class me {
 public:
  virtual void print() { cout << "me!\n"; }
};

class you:public me {
 public:
  virtual void print() { cout << "you!\n"; }
  void printPower() { cout << "big you!\n"; }
};
