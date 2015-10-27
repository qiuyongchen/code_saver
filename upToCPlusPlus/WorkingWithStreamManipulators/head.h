#include <iostream>
#include <iomanip>
using namespace std;

double readNumber() {
  double temp;
  cin >> temp;
  char c;
  c = cin.get();

  if (cin.peek() == '\n')
    cin.ignore();

  return temp;
}

double printFormatted(double x,double y) {
  cout << setw(12) << setfill('0') << left << x;
  cout << fixed << setprecision(2) << scientific << y << endl;
}
