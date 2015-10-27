#include "GayFoolShy.h"
#include <iostream>
using namespace std;

GayFoolShy::GayFoolShy(const string& name,
             const string& fName,
             double fBalance,
             const string& gName,
		       double gBalance):FuErDai
					(fName, "wlxead", fBalance),
					GuanErDai(gName, "wlxead", gBalance) {
  name_ = name;
}
 
string GayFoolShy::getName() const {
  return name_;
}

double GayFoolShy::getBalance() const {
  return FuErDai::getBalance() + GuanErDai::getBalance();
}
