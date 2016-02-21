#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
  int a;
  char c[122];

  cin >> a;
  cout << setiosflags(ios::showbase) << oct << a;

  while (cin >> c) {
    cout << " ";
    cout << c;
  }

  cout << endl;
  return 0;
}
