#ifndef _Counter_H
#define _Counter_H
#include <iostream>
#include <map>
#include <string>
using std::istream;
using std::map;
using std::string;
class Counter {
    public:
        void extract(string);
        int query(string);
    private:
        map<string, int>m;
};
#endif
