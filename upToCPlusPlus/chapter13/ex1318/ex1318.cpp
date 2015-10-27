/***************************************************
/* copyright by SuperSnow Company.
/* GLC.
/* everyone can copy the source for him or anyother,
/* but not change it and use for bussiness.
/***************************************************/

#include "CarbonFootprint.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  // vectors of pointers to CarbonFootprint.
  CarbonFootprint *carbon[3];

  // creat objects...
  Building bigHouse(222.3, 5465.45);
  bigHouse.getCarbonFootprint();

  Car bigCar(325435.456);
  bigCar.getCarbonFootprint();

  Bicycle bigCycle;
  bigCycle.getCarbonFootprint();
  cout << endl;
  // the following part of this is about the pointers.
  // assign the address to the arrey of the pointers to CarbonFontprint class.
  carbon[0] = &bigHouse;
  carbon[0]->getCarbonFootprint();

  carbon[1] = &bigCar;
  carbon[1]->getCarbonFootprint();

  carbon[2] = &bigCycle;
  carbon[2]->getCarbonFootprint();
  return 0;
}

