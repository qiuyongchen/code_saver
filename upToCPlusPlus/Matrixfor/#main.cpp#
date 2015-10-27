#include <iostream>
#include "matrix.h"
using namespace std;
int main() {
  int n;
  cin >> n;
  n = n % 21;
  if (n == 0) {
      n = 1;
  }
  Matrix m(n);
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        m.setElement(i, j, i * n + j);
  }
  m.print();
  cout << endl;
  Matrix c = m.transposition();
  c.print();
  Matrix x = m.multiply(c);
  cout << endl;
  x.print();
  return 0;
}
