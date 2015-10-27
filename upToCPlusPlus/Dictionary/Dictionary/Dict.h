/*#include <iostream>
#include <string>
#include <map>
using namespace std;

class Dict {
 public:
    void remove(string str) {dictionary.erase(str);}
    string& operator[](string str) {
        for (int i = 0; i < str.length(); i++)
            str[i] = (str[i] <= 'Z') ? (str[i] - 'A' + 'a') : str[i];
        if (dictionary.find(str) == dictionary.end())
            dictionary[str] = "*** not in dictionary";
        return dictionary[str];
    }
    int size() {
        int sizeTemp = 0;
        for (map<string, string>::iterator it = dictionary.begin();
            it != dictionary.end(); ++it)
            if (it->second != "*** not in dictionary")
                sizeTemp++;
        return sizeTemp;
    }
    friend ostream& operator<<(ostream& out, Dict D) {
        for (map<string, string>::iterator it = D.dictionary.begin();
            it != D.dictionary.end(); ++it)
            if (it->second != "*** not in dictionary")
                cout << it->first << "->" << it->second << endl;
        return out;
    }
 private:
    map<string, string> dictionary;
};
*/


#include <iostream>
#include <string>
#include <map>
using namespace std;
 
class Dict {
 private:
    map<string, string> d;
    map<string, string>::iterator i;
    int count;
 
 public:
    Dict() {}
    void remove(string word) {
        for (string::iterator p = word.begin(); p != word.end(); p++) {
            if (*p >= 'A' && *p <= 'Z')
                *p = *p + 32;
        }
         d.erase(word);
    }
    int size() {
        int count = 0;
         for (i= d.begin(); i!= d.end(); i++) {
             if (i->second != "*** not in dictionary")
              count++;
         }
         return count;
    }
    string& operator[](string word) {
       for (string::iterator p = word.begin(); p != word.end(); p++) {
            if (*p >= 'A' && *p <= 'Z')
                *p = *p + 32;
        }
        d.insert(make_pair(word, "*** not in dictionary"));
        return d[word];
      }
    friend ostream& operator<<(ostream& out, const Dict& a) {
        map<string, string>::const_iterator j;
        for (j = a.d.begin(); j != a.d.end(); j++) {
            if (j->second != "*** not in dictionary")
                out << (*j).first << "->" << (*j).second << endl;
        }
        return out;
    }
};
 