#include <iostream>
#include <string>
#include "R18.h"
#include <sstream>
using namespace std;


void R18::date_a_girl(const int &name) {
  stringstream ss;
  string s;
  ss << name;
  ss >> s;
  if (date.length() != 0) {
    date += "," + s;
  } else {
    date += s;
  }
}

std::string R18::girls_dated() const {
  return date;
}

