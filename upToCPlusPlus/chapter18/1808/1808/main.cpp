// this is a program using iterators that demonstrates the use of
// rend and rbegin.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "please input the string:\n";
    cin >> str;
    cout << "after using iterator demonstrates the use of rbegin and rend:\n";

    // be careful that the iterator option should be 'reverse_iteratro'.
    for (string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
        cout << *it;
    }

    cout << endl;
    return 0;
}
