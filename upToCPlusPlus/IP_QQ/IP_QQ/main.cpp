#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main() {
    int n;
    string qq, ip;
    map<string, set<string>> qqAsKey, ipAsKey;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> qq >> ip;
        qqAsKey[qq].insert(ip);
        ipAsKey[ip].insert(qq);
    }
    cin >> ip;
    if (ipAsKey.find(ip) == ipAsKey.end()) {
        cout << "no qq" << endl;
    } else {
        cout << ip << " ==> [ ";
        for (set<string>::iterator it = ipAsKey[ip].begin();
            it != ipAsKey[ip].end(); ++it)
            cout << *it << " ";
        cout << "]" << endl;
    }
    cin >> qq;
    if (qqAsKey.find(qq) == qqAsKey.end()) {
        cout << "no ip" << endl;
    } else {
        cout << qq << " ==> [ ";
        for (set<string>::iterator it = qqAsKey[qq].begin();
            it != qqAsKey[qq].end(); ++it)
            cout << *it << " ";
        cout << "]" << endl;
    }
    return 0;
}
