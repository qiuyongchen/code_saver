#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    string str;
    cout << "input the string:\n";
    cin >> str;
    // using the rot13 algorithm.
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i] <= 'M') str[i] += 13;
            else str[i] = str[i] + 13 - 26;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] <= 'm') str[i] += 13;
            // if the letters is located in 'n' to 'z', then we should do this
            else str[i] = str[i] + 13 - 26;
        }
    }
    cout << "after the rot13, the string is:\n" << str << endl;
    return 0;
}
