// ex2212.cpp

#include <iostream>
#include <vector>
using namespace std;

template<typename T> bool palindrome(vector<T> vec);

int main() {
    vector<int> vec;
    int n;
    int temp;

    cout << "how many elements do you have?" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);;
    }

    if (palindrome(vec))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}

template<typename T> bool palindrome(vector<T> vec) {
    // tell the compiler that the following two guys are type, not other.
    typedef vector<T>::iterator veciterator;
    typedef vector<T>::reverse_iterator rvecitrator;
    rvecitrator rit;
    veciterator it;

    // if there are two elements that in two different way and different.
    for (it = vec.begin(), rit = vec.rbegin();
        it != vec.end(); ++it, ++rit) {
            if (*it != *rit)
                return false;
    }

    return true;
}
