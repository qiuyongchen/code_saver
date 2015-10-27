#include <iostream>
using namespace std;

#include <iomanip>
#include <cmath>

int main() {
  int  n;
  double sum = 10000.0;
  cin >> n;

  n %= 100;

  for (int i = 0; i < n; i++) {
    sum = sum + sum * 0.05;
  }

  cout.precision(2);
  cout << setiosflags(ios::fixed) << static_cast<int>(sum) << endl;
  return 0;
}
