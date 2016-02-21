#include <iostream>
using namespace std;

template<class T>
class A {
 public:
  class B;
  A() {aaa = "this is A";}
  void print();
  template<class T>
  class B{
  public:
    friend class A<T>;
    B() {bbb = "this is B";}
    void print();
  private:
      string bbb;
  };

 private:
    string aaa;
};

template<typename T>
void A<T>::print() {
  cout << aaa << endl;
}

template<typename T>
void B<T>::print() {
  cout << bbb << endl;
}

