// Created by YongChenQiu.
// ex1210.cpp
#include "Package.h"
#include <iostream>
using namespace std;

int main() {
  Package a("wlxead", "JiansheRod", "Zhanjiang", "Guangdong", "524000",
	  "redleaf", "D.C", "Washington", "None","865799", 16.7, 45.8);
  a.haveALook(); 
  cout << a.calculateCost() << endl << endl;

  TwoDayPackage b("wlxeadb", "JiansheRod", "Zhanjiang", "Guangdong", "524000",
	    "redleafb", "D.C", "Washington", "None","865799", 16.7, 45.8, 1000);
  b.haveALook(); 
  cout << b.calculateCost() << endl << endl;

  OvernightPackage c("wlxeadc", "JiansheRod", "Zhanjiang", "Guangdong", "524000",
	    "redleafc", "D.C", "Washington", "None","865799", 16.7, 45.8, 44.2);
  c.haveALook(); 
  cout << c.calculateCost() << endl;

  return 0;
}
