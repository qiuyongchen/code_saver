#include <iostream>
#include <string>
using namespace std;

class Complex {
  friend ostream & operator<< (ostream &out, Complex &c);
  friend istream & operator>> (istream &in, Complex &c);
 private:
  string realS;
  string imagS;
  int real = 0;
  int imag = 0;
  bool valid;
};
