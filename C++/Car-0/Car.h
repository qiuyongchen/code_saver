#ifndef WLXEAD
#define WLXEAD
#include <iostream>
using namespace std;

class Car {
public:
  void setManufacturer(string ts);
  void setDisplacement(double td);
  string getManufacturer();
  double getDisplacement();

private:
  string manufacturer;
  double displacement;
};

#endif
