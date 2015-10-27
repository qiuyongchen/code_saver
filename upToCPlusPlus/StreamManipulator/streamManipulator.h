#include <iostream>
#include <iomanip>
using namespace std;

class StreamManipulator {
 public:
  StreamManipulator(int n) {number = n;}
  void setNumber(int n) {number = n;}
  void showInDecimal() {cout << showbase << dec << "As a decimal number "
                             << number << endl;}
  void showInOctal() {cout << showbase << oct << "As a octal number "
                             << number << endl;}
  void showInHexadecimal() {cout << showbase << hex 
                               << "As a hexadecimal number " << number << endl;}
  void printInPrecision(double y, int x);
  void convertFahrenToCelsis(int FahrenTemp);
 private:
  int number;
};
