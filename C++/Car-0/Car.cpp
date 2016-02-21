#include "Car.h"
#include <iostream>
using namespace std;

void Car::setManufacturer(string ts) {
  manufacturer = ts;
}

void Car::setDisplacement(double td) {
  displacement = td;
}

string Car::getManufacturer() {
  return manufacturer;
}

double Car::getDisplacement() {
  return displacement;
}
