#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

std::string change1(char* st) {
  string s;
  s = (string)st;
  return s;
}

void change2(std::string st1, char* st2) {
  int i, j;

  for (i = 0; i < st1.length(); i++) {
    st2[i] = st1[i];
  }

  st2[i] = '\0';
}
