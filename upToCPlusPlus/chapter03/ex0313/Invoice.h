// Invoice.h
// The declaration and definition of the Invoice class
#include <iostream>
#include <string>
using namespace std;

class Invoice {
 public:
  Invoice();
  void setNumber(string num);
  string getNumber() const;
  void setDescription(string des);
  string getDescription() const;
  void setQuantity(int qua);
  int getQuantity() const;
  void setPrice(int pri);
  int getPrice() const;
  int getInvoiceAmount() const;
 private:
  string number;
  string description;
  int quantity;
  int price;
};

// The constructor of the Invoice class.
Invoice::Invoice() {
  setNumber("");
  setDescription("");
  setQuantity(0);
  setPrice(0);
}

// Set the number.
void Invoice::setNumber(string num) {
  number = num;
}

string Invoice::getNumber() const {
  return number;
}

// Set the description.
void Invoice::setDescription(string des) {
  description = des;
}

string Invoice::getDescription() const {
  return description;
}

// Set the quantity.
// If the value of qua is not positive, then quantity is set to 0.
void Invoice::setQuantity(int qua) {

  if (qua < 0) {
    quantity = 0;
  } else {
    quantity = qua;
  }

}

int Invoice::getQuantity() const {
  return quantity;
}

// Set the price.
// If the value of pri is not positive, then price is set to 0.
void Invoice::setPrice(int pri) {

  if(pri < 0) {
    price = 0;
  } else {
    price = pri;
  }

}

int Invoice::getPrice() const {
  return price;
}

// Calculate the amount.
int Invoice::getInvoiceAmount() const {
  return quantity * price;
}
