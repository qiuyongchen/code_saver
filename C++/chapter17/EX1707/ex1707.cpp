#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // open the file.
    ofstream ou("oldmast.dat", ios::out);
    if (!ou) {
        cerr << "opne file fail\n";
        exit(1);
    }
    int account;
    string name;
    double balance;

    while(cin >> account >> name >> balance) {
    ou << account << ' ' << name << ' ' << balance << endl;
    cout << endl;
    }
    
    // open the file
    ofstream ouo("trans.dat", ios::out);
    if (!ouo) {
        cerr << "opne file fail\n";
        exit(1);
    }
    while (cin >> account >> balance) {
    ouo << account << ' ' << balance << endl;
    cout << endl;
    }
    ouo.close();

    return 0;
}
