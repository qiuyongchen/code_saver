#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
 
#include <string>
 
class BankAccount {
public:
void reset();
int getBalance() const;
void setBalance(int newBalance);
std::string getName() const;
void setName(std::string newName);
private:
int balance;
std::string name;
};
 
#endif
