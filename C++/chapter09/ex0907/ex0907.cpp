#include "Time.h"
#include <iostream>

int main() {
  Time tOne(23, 51, 50);

  tOne.printStandard();
  cout << endl;

  for ( int i = 1; i < 1000; i++ ) {
    tOne.tick();
    tOne.printStandard();
    cout << endl;
  }

  return 0;
}
