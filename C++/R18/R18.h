#include <iostream>
#include <string>
using namespace std;

class R18 {
 public:
  static R18 *getInstance() {
    static R18 r18;
    return &r18;
  }
  void date_a_girl(const int &name);
  std::string girls_dated() const;
 private:
  R18() {if(false) cout << " ";}
  ~R18() {}
  string date;
};
