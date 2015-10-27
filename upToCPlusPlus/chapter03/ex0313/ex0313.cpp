// ex0313.cpp
// Created by qiuyongchen.
#include <iostream>
using namespace std;

#include "Invoice.h"

int main() {
  Invoice invoiceOne;

  cout << invoiceOne.getNumber() << '-' << invoiceOne.getDescription() << '-'
       << invoiceOne.getQuantity() << '-' << invoiceOne.getPrice() << endl;

  invoiceOne.setNumber("Hello");
  invoiceOne.setDescription("World");
  invoiceOne.setQuantity(33);
  invoiceOne.setPrice(99);

  cout << invoiceOne.getNumber() << '-' << invoiceOne.getDescription() << '-'
       << invoiceOne.getQuantity() << '-' << invoiceOne.getPrice() << endl;

  Invoice invoiceTwo;

  cout << invoiceTwo.getNumber() << '-' << invoiceTwo.getDescription() << '-'
       << invoiceTwo.getQuantity() << '-' << invoiceTwo.getPrice() << endl;

  invoiceTwo.setQuantity(-55);
  invoiceTwo.setPrice(-99);

  cout << invoiceTwo.getNumber() << '-' << invoiceTwo.getDescription() << '-'
       << invoiceTwo.getQuantity() << '-' << invoiceTwo.getPrice() << endl;

  return 0;
}
