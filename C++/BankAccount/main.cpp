

    #include <iostream>
    #include "BankAccount.h"
     
    void display(const BankAccount &b) {
    std::cout << b.getBalance() << "-" << b.getName() << std::endl;
    }
     
    int main() {
    BankAccount b;
    int p, q = 5;
    b.setBalance(1205);
    b.setName("Kotenbu");
    display(b);
    b.reset();
    display(b);
    b.setName("");
    display(b);
    b.setName("Oreki");
    while (q--) {
    std::cin >> p;
    b.setBalance(p);
    display(b);
    }
    return 0;
    }

