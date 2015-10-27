// Created by YongChenQiu.
// Package.h
// Package Inheritance Hierarcby
#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// The declaration of class Package.
class Package {
 public:
  // The construtor of class Package, we check pw and cpo.
  Package(string sn, string sa, string sc, string ss, string szc,
	  string rn, string ra, string rc, string rs, string rzc,
	  double pw, double cpo);
  string getSenderName();
  string getSenderAddress();
  string getSenderCity();
  string getSenderState();
  string getSenderZipCode();

  string getRecipientName();
  string getRecipientAddress();
  string getRecipientCity();
  string getRecipientState();
  string getRecipientZipCode();

  double getPackageWeigth();
  double getCostPerOunce();

  // The function haveALood just output the infomation.
  void haveALook();
  // The function calculateCost returns the cost by multiplying the
  // 'packageWeight' by the 'costPerOunce'.
  double calculateCost();
 private:
  string senderName;
  string senderAddress;
  string senderCity;
  string senderState;
  string senderZipCode;

  string recipientName;
  string recipientAddress;
  string recipientCity;
  string recipientState;
  string recipientZipCode;

  double packageWeight;
  double costPerOunce;
};

// The implement of the construtor of class Package.
Package::Package(string sn, string sa, string sc, string ss, string szc,
                 string rn, string ra, string rc, string rs, string rzc,
                 double pw, double cpo) {
  senderName = sn;
  senderAddress = sa;
  senderCity = sc;
  senderState = ss;
  senderZipCode = szc;

  recipientName = rn;
  recipientAddress = ra;
  recipientCity = rc;
  recipientState = rs;
  recipientZipCode = rzc;

  // To check if the pw is valid.
  if (pw > 0) {
    packageWeight = pw;
  } else {
    throw invalid_argument ("invalid packageWeight");
  }

  // To check if the cpo is valid.
  if (cpo > 0) {
    costPerOunce = cpo;
  } else {
    throw invalid_argument ("invalid costPerOunce");
  }

}

string Package::getSenderName() {
  return senderName;
}

string Package::getSenderAddress() {
  return senderAddress;
}

string Package::getSenderCity() {
  return senderCity;
}

string Package::getSenderState() {
  return senderState;
}

string Package::getSenderZipCode() {
  return senderZipCode;
}

string Package::getRecipientName() {
  return recipientName;
}

string Package::getRecipientAddress() {
  return recipientAddress;
}

string Package::getRecipientCity() {
  return recipientCity;
}

string Package::getRecipientState() {
  return recipientState;
}

string Package::getRecipientZipCode() {
  return recipientZipCode;
}

double Package::getPackageWeigth() {
  return packageWeight;
}

double Package::getCostPerOunce() {
  return costPerOunce;
}

void Package::haveALook() {
cout << "The package is:\n"
     << "********************************************************************\n"
     << "    from: "
     << getSenderName() << " "
     << getSenderAddress() << " "
     << getSenderCity() << " "
     << getSenderState() << " where the Zip is "
     << getSenderZipCode() << "\n"
     << "      to: "
     << getRecipientName() << " in "
     << getRecipientAddress() << ", "
     << getRecipientCity() << ", "
     << getRecipientState() << " where the Zip is "
     << getRecipientZipCode() << ".\n"
     << "********************************************************************\n";
}

// The implement of function calculateCost of Package.
double Package::calculateCost() {
  return packageWeight * costPerOunce;
}


// The declaration of class TwodayPackage which derive from Package.
class TwoDayPackage:public Package {
 public:
  TwoDayPackage(string sn, string sa, string sc, string ss,
                             string szc,string rn, string ra, string rc,
                             string rs,string rzc,double pw, double cpo,
                             double ff);
  double calculateCost();
 private:
  double flatFee;
};

// The implement of construtor of class TwoDayPackage.
TwoDayPackage::TwoDayPackage(string sn, string sa, string sc, string ss,
                             string szc,string rn, string ra, string rc,
                             string rs,string rzc,double pw, double cpo,
                             double ff):Package(sn, sa, sc,ss, szc, rn,
    					 ra, rc, rs, rzc, pw, cpo) {
			       flatFee = ff;
}

// The implement of function calculateCost of class TwoDayPackage.
double TwoDayPackage::calculateCost() {
  return flatFee + getPackageWeigth() * getCostPerOunce();
}


// The declaration of class OvernightPackgae.
class OvernightPackage:public Package {
 public:
  OvernightPackage(string sn, string sa, string sc, string ss,
                             string szc,string rn, string ra, string rc,
                             string rs,string rzc,double pw, double cpo,
                             double cfo);
  double calculateCost();
 private:
  double chargeForOvernight;
};

// The implement of construtor of class OvernightPackage.
OvernightPackage::OvernightPackage(string sn, string sa, string sc, string ss,
                             string szc,string rn, string ra, string rc,
                             string rs,string rzc,double pw, double cpo,
                             double cfo):Package( sn, sa, sc, ss, szc, rn,
    			                     ra, rc, rs, rzc, pw, cpo) {
			       chargeForOvernight = cfo;
}

// The implement of calculateCost of class OverNightPackage.
double OvernightPackage::calculateCost() {
  // remember that, when we deriving a class from a public class, the private
  // member of the base class can be accessed by its public member function.
  // And we use :: to get the redefine function of base class.
  return getPackageWeigth() * (getCostPerOunce() + chargeForOvernight);
}

#endif
