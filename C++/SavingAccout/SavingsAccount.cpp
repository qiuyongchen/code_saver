#include "SavingsAccount.h"

using namespace std;

double SavingsAccount::annualInterestRate = 0.0;

void SavingsAccount::calculateMonthlyInterest() {
  savingsBalance += savingsBalance * (annualInterestRate / 12);
}

void SavingsAccount::modifyInterestRate(double newRate) {
  if (newRate < 0)
    annualInterestRate = newRate;
  else
    annualInterestRate = 0.03;
}

