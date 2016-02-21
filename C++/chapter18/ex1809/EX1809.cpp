// read in several strings and print only those ending in 'r' or 'ay',
// only lowercase letter should be consider.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "how many strings do you want to check out? :\n";
    int n;
    cin >> n;
    while (n--) {
        cout << "input the string:\n";
        cin >> str;
        if (str[str.length() - 1] == 'r') {
            cout << "this string is ok: " << str << endl;
        } else if (str[str.length() - 1] == 'y'
            && str[str.length() - 2] == 'a') {
                cout << "this string is ok: " << str << endl;
        } else {
            cout << "this string is not ok" << endl;
        }
    }
    return 0;
}
