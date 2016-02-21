#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap(int &, int &);
  int main() {
  int a, b;
  cin >> a >> b;
  swap(a, b);
  cout << a << " " << b << endl;
  return 0;
}

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}
