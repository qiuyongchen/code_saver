#include <iostream>
#include <string>
#include "stack.h"
#include "MidToLast.h"
using namespace std;
 
int main() {
  string str;
  string d;
  Stack s;
  getline(cin, d);
  int len = d.length();
  for (int i = len - 1; i > 1; i--) {
    s.push(d[i]);
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  cout << s.size() << endl;
  getline(cin, str);
  MidToLast mtl;
  string strtemp = mtl.transfer(str);
  cout << strtemp << endl;

  return 0;
}
