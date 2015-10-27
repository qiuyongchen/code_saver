
#ifndef BOOKI_H
#define BOOKI_H

#include <iostream>
#include <string>
using namespace std;
class BookIndex {
public:
        BookIndex();
        BookIndex(const string name, const string author, const int year);
        ~BookIndex();
        string getTitle() const;
        string getAuthorName() const;
        void setCopyright(const int year_wlxead);
        int getCopyright() const;
private:
        string title;
        string authorName;
        int copyright;
}; 

#endif
