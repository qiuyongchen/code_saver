/***************************************************
/* copyright by SuperSnow Company.
/* GLC.
/* everyone can copy the source for him or anyother,
/* but not change it and use for bussiness.
/***************************************************/

#include <iostream>
#include <string>
using namespace std;
// The declaration of the base class CarbonFontprint
class CarbonFootprint {
 public:
  virtual void getCarbonFootprint() = 0;
  virtual ~CarbonFootprint() {}
};

// The declaration of the class Building derive from CarbonFootprint
class Building: public CarbonFootprint {
 public:
  Building(double a, double b) {elePerMonth = a; coalPerMonth = b;}
  virtual void getCarbonFootprint();
  virtual ~Building() {}
 private:
  double elePerMonth;  // the eletricity used by the house each month.
  double coalPerMonth;  // the coal burn by the house each month.
};

// The implement of the function in class Building.
void Building::getCarbonFootprint() {
cout << "The total of CO2 produced by the bigHouse is " << elePerMonth * 12
      * 0.997 + coalPerMonth * 12 * 2.493 << " KG!" << endl;
}

// The declaration of the class Car derive from CarbonFootprint
class Car: public CarbonFootprint {
 public:
  Car(double a) {oilFire = a;}
  virtual void getCarbonFootprint();
  virtual ~Car() {}
 private:
  double oilFire;  // the total number of oid burn by the car.
};

void Car::getCarbonFootprint() {
  cout << "The total of CO2 produced by the Car is " << oilFire * 0.785
       << " KG!" << endl;
}

// The declaration of the class Bicycle derive from CarbonFootprint
class Bicycle: public CarbonFootprint {
 public:
  virtual void getCarbonFootprint();
  virtual ~Bicycle() {}
 private:  // there will be no CO2 produced by the Bicycle.
};

void Bicycle::getCarbonFootprint() {
  cout << "The total of CO2 produced by the Bicycle is 0 KG!" << endl;
}
