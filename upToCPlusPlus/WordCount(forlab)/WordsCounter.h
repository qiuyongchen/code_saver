#include <iostream>
#include <string>
#include <set>
using namespace std;


class WordsCounter {
 public:
    explicit WordsCounter(int n) {
        bound = n;
    }

    int operator()(string s) {
        set<string> m;
        for (int i = 0; i < s.length(); i++) {
            if (s[0] == ' ') {
                s = s.substr(1);  // no whitespace at the beginning.
                i = 0;
            } else {
                int j = 0;
                while (s[j] != ' ' && s[j] != '\0') j++;
                string temp = s.substr(0, j);  // find the words.
                s = s.substr(j);
                if (temp.size() >= bound) {
                    m.insert(temp);
                }
                i = 0;
            }
        }
        return m.size ();
    }

    void setBound(int n) {
        bound = n;
    }

 private:
    int bound;
};