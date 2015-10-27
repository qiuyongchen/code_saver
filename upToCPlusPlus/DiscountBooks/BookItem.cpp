#include "BookItem.h"
#include <iostream>
using namespace std;

BookItem::BookItem(const string& bookName, double salesPrice) {
  name_ = bookName;
  price_ = salesPrice;
}

string BookItem::getName() const {
  return name_;
}

double BookItem::netPrice(int cnt) const {
  return price_ * cnt;
}

