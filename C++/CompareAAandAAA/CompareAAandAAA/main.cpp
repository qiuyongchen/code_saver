#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // lexicographically comparation.
    if (string("aa") < string("aaa"))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    // the value of npos.
    int temp = 87654;
    string str = "1234";

    stringstream ss;
    ss << temp;
    ss >> str;
    for (string::reverse_iterator it = str.rbegin(); it!= str.rend(); ++it)
        cout << *it;
    cout << endl;

    cout << str << endl;

    cout << temp << endl;

    cout << temp - 99 << endl;

    return 0;
}
