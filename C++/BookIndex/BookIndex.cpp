#include <iostream>
#include <string>
#include "BookIndex.h"
using namespace std;

BookIndex::BookIndex() {

}

// I am qiuyongchen.
BookIndex::BookIndex(const string nameI, const string authorI, const int yearI) {
  title = nameI;
  authorName = authorI;
  copyright = yearI;
}

// don't know what to say.
BookIndex::~BookIndex() {

}

string BookIndex::getTitle() const {
  return title;
}

string BookIndex::getAuthorName() const {
  return authorName;
}

void BookIndex::setCopyright(const int year_wlxead) {
  copyright = year_wlxead;
}

int BookIndex::getCopyright() const {
  return copyright;
}
