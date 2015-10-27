#include "Counter.h"
using namespace std;

void Counter::extract(string s) {
  string temp = s;
  string tempShort;
  if (temp.find(";") == -1) {
    m[temp] = 1;
  } else {

    while (temp.length()) {
      int pos = temp.find(";");
      if (pos != -1) {
        tempShort = temp.substr(0, pos);
        m[tempShort] += 1;
        temp = temp.substr(pos + 1);
      } else {
	m[temp] += 1;
	break;
      }
    }

  }
}

int Counter::query(string s) {
  return m[s];
}
