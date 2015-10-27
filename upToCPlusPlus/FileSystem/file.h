#include <iostream>
#include <string>
using namespace std;

class FileSymItem {
 protected:
  string name;
 public:
  FileSymItem() {
  }

  void rename(const string& nameTemp) {
    name = nameTemp;
  }

  virtual int getSize() = 0;

};

class File : public FileSymItem {
 public:
  File(const string& nameTemp, const int& s = 0) {
    rename(nameTemp);
    size = s;
  }

  virtual int getSize() {
    return size;
  }

  void setSize(const int& sizeTemp) {
    size = sizeTemp;
  }

  ~File() {
    cout << "Del File : " << name << endl;
  }

 private:
  int size;
};

class Dir : public FileSymItem {
 private:
  static const int MAX_ITEM_COUNT = 20;
  FileSymItem* children[MAX_ITEM_COUNT];
  int count;

 public:
  explicit Dir(const string& nameTemp) {
    FileSymItem::name = nameTemp;
    count = 0;
  }

  void addFileSymItem(FileSymItem* newItem) {
    children[count++] = newItem;
  }

  void delFileSymItem(FileSymItem* delItem) {
    for (int i = 0; i < count; ++i) {

      if (children[i] == delItem) {

	for (int j = i; j < count - 1; ++j) {
          children[j] = children[j + 1];
        }

        --count;
        break;
      }

    }

  }

  virtual int getSize() {
    int sum = 0;

    for (int i = 0; i < count; ++i) {
      sum += children[i]->getSize();
    }

    return sum;
  }

  ~Dir() {
    cout << "Del Dir : " << name << endl;
  }
};
