#include "AccountManager.h"
#include <iostream>
using namespace std;

AccountManager::AccountManager() {
  head_ = NULL;
}

AccountManager::~AccountManager() {

  while (getAccountNumber() > 0) {
    while (head_ != NULL) {
      Account *tempFind = head_;
      head_ = head_->getNext();
      delete tempFind;
    }
  }
}

void AccountManager::open(const string& name, double balance) {
  Account *temp = new Account(name, balance);

  if (head_ == NULL) {
    head_ = temp;
  } else {
    Account *tempFind;
    tempFind = head_;
    while (tempFind->getNext() != NULL) {
      tempFind = tempFind->getNext();
    }
    tempFind->setNext(temp);
  }

}

void AccountManager::close(const string& name) {

  Account *tempFind;
  tempFind = head_;

  // Here we want to get the pointer that point to the location before the
  // Account which we want to close.
  while (tempFind->getNext() != NULL && tempFind->getNext()->getName() != name
	 && tempFind->getName() != name) {
    tempFind = tempFind->getNext();
  }

  // if the pointer we found is the last one in the list, it means that there
  // is no the Account which we want to found(because the next one is NULL.)
  if (tempFind->getNext() == NULL) {
    cout << "no such account" << endl;

    // if
  } //else if (tempFind->getNext()->getName() != name) {
    //cout << "no such account" << endl;
  //  } 
else {
    Account *forDelete;
    forDelete = tempFind->getNext();
    tempFind->setNext(tempFind->getNext()->getNext());
    delete forDelete;
  }

}

int AccountManager::getAccountNumber() {
  Account *tempFind;
  tempFind = head_;
  int num = 0;
  while (tempFind != NULL) {
    tempFind = tempFind->getNext();
    num++;
  }
  return num;
}

