#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main() {
    string str;
    string strFre = "etaoinsrhldcumfpgwybvkxjqz";
    int subScripOfStrFre = 0;
    cout << "input the string:\n";
    getline(cin, str);
    map<char, int> mapOfFre;

    // convert all uppercase character to lowercase.
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    string strCopy(str.length(), '0');

    // find out the frequecy.
    for (string::iterator it = str.begin(); it != str.end(); ++it) { 
        if (*it >= 'a' && *it <= 'z')
            mapOfFre[*it]++;
    }

    // decrypt the 'rot13' using simple frequency substituation.
    while (!mapOfFre.empty()) {
        char mostUsed;
        int index = 0;

        // find out the one that was used most frequent.
        for (map<char, int>::iterator it = mapOfFre.begin();
            it != mapOfFre.end(); ++it) {
                if (it->second > index) {
                    mostUsed = it->first;
                    index = it->second;
                }
        }

        // changing the most used character to the most frequency.
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == mostUsed && strCopy[i] == '0') {
                str[i] = strFre[subScripOfStrFre];
                strCopy[i] = '1';
            }
        }

        // delete the most used character in the map and change the
        // 'subScripOfStrFre' to point to the next character.
        mapOfFre.erase(mostUsed);
        subScripOfStrFre++;
    }
    cout << "\nthe possibility message is:\n" << str << endl;
    cout << "\nand it has been written to the file \"possibility.txt\"\n";

    // write the possiblities to a file called 'possibility.txt'
    fstream fs("possibility.txt", ios::out);
    fs << str << endl;
    fs.close();

    return 0;
}
