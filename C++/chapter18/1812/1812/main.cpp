#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "input the string:\n";
    cin >> str;
    // prints the string backward
    for (string::reverse_iterator it = str.rbegin(); it!= str.rend(); ++it) {
        // convert all uppercase characters to lowercase, convert all lowercase
        // character to uppercase.
        if (*it >= 'a') {
            char c = *it - 'a' + 'A';
            cout << c;
        } else {
            char c = *it - 'A' + 'a';
            cout << c;
        }
    }
    return 0;
}
