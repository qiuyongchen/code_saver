#include "Polynomia.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

int main() {
  Polynomia polA;
  int n;

  cout << "Please input the coefficient and exponent(less than 5)" << endl;

  for (int i = 0; i < 5; i++) {
    cin >> n;
    polA.set(n, i);
  }

  Polynomia polB, polC, polD, polE, polF, polG, polH;

  cout << "Please input the coefficient and exponent(less than 5)" << endl;

  for (int i = 0; i < 5; i++) {
    cin >> n;
    polB.set(n, i);
  }

  polC = polA + polB;
  polD = polA - polB;

  cout << "PolA is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polA.get(i) << "X" << i << ")";
    if (i != 4)
      cout << "+";

  }
  cout << endl;

  cout << "PolB is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polB.get(i) << "X" << i << ")";

    if (i != 4)
      cout << "+";

  }
  cout << endl;

  cout << "polC = polA + polB, PolC is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polC.get(i) << "X" << i << ")";

    if (i != 4)
      cout << "+";

  }
  cout << endl;

  cout << "polD = polA - polB,PolD is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polD.get(i) << "X" << i << ")";

    if (i != 4)
      cout << "+";

  }
  cout << endl;

  polC += polA;
  cout << "polC += polA, PolC is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polC.get(i) << "X" << i << ")";

    if (i != 4)
      cout << "+";

  }
  cout << endl;

  polD -= polB;
  cout << "polD -= polB,PolD is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polD.get(i) << "X" << i << ")";

    if (i != 4)
      cout << "+";

  }
  cout << endl;


  cout << "\n\n" <<  endl;
  cout << "please the new polynomia(exponent less than 4):" << endl;

  for (int i = 0; i < 3; i++) {
    cin >> n;
    polE.set(n, i);
  }

  cout << "please the new polynomia(exponent less than 4):" << endl;
  for (int i = 0; i < 3; i++) {
    cin >> n;
    polF.set(n, i);
  }

  polG = polE * polF;
  cout << endl << "polG = polE * polF, PolE is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polG.get(i) << "X" << i << ")";

    if (i != 4)
      cout << "+";

  }
  cout << endl;

  polE *= polF;
  cout << endl << "polE *= polF, PolE is:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "(" << polE.get(i) << "X" << i << ")";

    if (i != 4)
      cout << "+";

  }
  cout << endl;

  cout << "Game Over" << endl;

  return 0;
}
