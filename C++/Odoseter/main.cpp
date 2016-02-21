#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;

  while (str != "0") {
    cout << str << endl;
    cin >> str;
  }

  return 0;
}
