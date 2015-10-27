#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  int n, q;
  double Kilo;

  cin >> n;

  cout << setw(15) << setiosflags(ios::left) << "Miles";
  cout << setw(15) << setiosflags(ios::left) << "Kilometers" << endl;

  for (int i = 0; i < n; i++) {
    cin >> q;
    cout << setw(15) << setiosflags(ios::left) << q;
    cout << setw(15) << setiosflags(ios::left) << setprecision(3)
	 << setiosflags(ios::fixed) << q * 1.609 << endl;
  }
  return 0;
}
