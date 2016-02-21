#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> account;
    vector<int> anotherAccount;
    // open the file "newmast.dat"
    ofstream outNewMaster("newmast.dat", ios::out);
    if (!outNewMaster) {
        cerr << "Open File Fail\n";
        exit(1);
    }
    // open the file "oldmast.dat"
    ifstream inOldMaster("oldmast.dat", ios::in);
    if (!inOldMaster) {
        cerr << "Open filse Fail\n";
        exit(1);
    }
    // open the file "trans.dat"
    ifstream inTransaction("trans.dat", ios::in);
    if (!inTransaction) {
        cerr << "Open filse Fail\n";
        exit(1);
    }
    // open the file "trans.dat"
    ifstream inAnotherTransaction("transanother.dat", ios::in);
    if (!inAnotherTransaction) {
        cerr << "Open filse Fail\n";
        exit(1);
    }

    // reseach for the update, if there is some update, record it.
    while (!inOldMaster.eof()) {
        int accountNumber;
        string name;
        double currentBalance;
        inOldMaster >> accountNumber >> name >> currentBalance;

        // find in the transaction.
        while (!inTransaction.eof()) {
            int accountNum;
            double dollarAmount;
            inTransaction >> accountNum >> dollarAmount;
            if (accountNumber == accountNum) {
                account.push_back(accountNum);
                currentBalance += dollarAmount;
            }
        }

        // find in another transaction.
        while (!inAnotherTransaction.eof()) {
            int accountNum;
            double dollarAmount;
            inAnotherTransaction >> accountNum >> dollarAmount;
            if (accountNumber == accountNum) {
                anotherAccount.push_back(accountNum);
                currentBalance += dollarAmount;
            }
        }

        outNewMaster << accountNumber << " " << name << " "
            << currentBalance
            << endl;
        inTransaction.clear();  // clear for the next input.
        inTransaction.seekg(0);  // position the pointer.
        inAnotherTransaction.clear();  // clear for the next input.
        inAnotherTransaction.seekg(0);  // position the pointer.
    }

    // to see if there is some data in trans.dat that do not fit in.
    inAnotherTransaction.clear();  // clear for the next input.
    inAnotherTransaction.seekg(0);  // position the pointer.
    inTransaction.clear();
    inTransaction.seekg(0);
    while (!inTransaction.eof()) {
        int accountNum;
        double dollarAmount;
        bool found = false;
        inTransaction >> accountNum >> dollarAmount;
        for (vector<int>::iterator it = account.begin();
            it != account.end(); ++it) {
            if (*it == accountNum)
                found = true;
        }
        if (!found)
            cout << "Unmatched transaction record for account number "
            << accountNum << endl;
    }
    while (!inAnotherTransaction.eof()) {
        int accountNum;
        double dollarAmount;
        bool found = false;
        inAnotherTransaction >> accountNum >> dollarAmount;
        for (vector<int>::iterator it = anotherAccount.begin();
            it != anotherAccount.end(); ++it) {
            if (*it == accountNum)
                found = true;
        }
        if (!found)
            cout << "Unmatched transaction record for account number "
            << accountNum << endl;
    }

    return 0;
}
