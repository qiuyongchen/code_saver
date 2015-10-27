#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
    const int SIZE = 1000;
    bitset<SIZE> sieve;

    // set all bits tobe 'ON'.
    sieve.flip();
    // set bit '0' and '1' tobe 'OFF'.
    sieve.reset(0);
    sieve.reset(1);

    int finalBit = sqrt( static_cast<double>(sieve.size()) + 1);

    // find out those prime number.
    for (int i = 2; i < finalBit; ++i) {
        // bit i is 'ON'.
        if (sieve.test(i)) {
            for (int j = 2 * i; j < SIZE; j += i) {
                sieve.reset(j);
            }
        }
    }

    int temp;
    cout << "please input the number you want to test:" << endl;
    cin >> temp;
    while (temp < 0 || temp > SIZE) {
        cout << "input invalid, please try again:" << endl;
        cin >> temp;
    }
    if (sieve.test(temp)) {
        cout << "the number is a prime number" << endl;
    } else {
        vector<int> vec;
        set<int> s;

        int copyOfTemp = temp;
        // find out those factors.
        for (int i = 2; i < temp; ++i) {
            if (copyOfTemp % i == 0) {
                vec.push_back(i);
                copyOfTemp /= i;
                i = 1;
                continue;
            }
        }

        // output those factors.
        for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            if (it != vec.begin())
                cout << " * ";
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}
