#include "Complex.h"
#include <sstream>
#include <cstdlib>
ostream& operator<< (ostream& out, Complex& c) {
  if (c.valid) {
    out << c.real;
    out << showpos << c.imag;
    out << "i" << endl;
  } else {
    out << "Invalid Data Entered" << endl;
  }
  return out;
}

istream& operator>> (istream& in, Complex& com) {
  char c;
  int flag = 1;
  string temp;
  int symReal = 1;
  int symImag = 1;
  while ((c = in.get()) != '\n') {

    // clean the whitespace.
    if (c == ' ') {
      continue;
    }

    // determine if .
    if ((c != 'i') && (c != '-')
	&& (c != '+')) {  // no '+' no '-' no 'i', so just make it a string.
      temp += c;
    } else {
      // if we meet the '+' or '-',it means that the real is end,real has no pos.
      if ((c == '+') || (c == '-')) {
	if (temp == "-" && c == '-') {
	  temp = "+";
	} else if (temp == "-" && c == '+') {
	  temp = "-";
        } else {
        stringstream ss;
        ss << temp;
        int i;
        ss >> i;
        com.real = i;
        temp = c;  // we have to take the negative position back for the imag.
        flag = 0;
	}
	// if we meet the 'i', it means that imag is end.
      } else if (c == 'i') {
        stringstream ss;
        ss << temp;
        int i;
        ss >> i;
        com.imag = i;
        temp = "0";
        flag = -1;
      }
    }
  }

  // if there is no 'i' like "2", then we have to do something.
  if (flag == 1) {
    stringstream ss;
    ss << temp;
    int i;
    ss >> i;
    com.real = i;
  }

  // if we really meet the 'i'(flag == -1), but i == 0, then it must be wrong.
  if ((flag == -1 || flag == 0) && com.imag == 0) {
    com.valid = false;
    in.clear(ios::badbit);
  } else {
    com.valid = true;
  }

  return in;
}
