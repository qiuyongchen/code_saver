#include "check.h"
#include <iostream>
using namespace std;
int number[1000][1000];
int main() {
    int row, test;
    int tmp;
    cin >> row >> test;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
          cin >> number[i][j];
        while (test--) {
            cin >> tmp;
        if (check(number, row, tmp))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        }
    return 0;
}
