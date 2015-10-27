#include <iostream>
#include <string>
using namespace std;

class Triangle {
public:
  Triangle();
  virtual void set(int aa, int bb, int cc);
  double area() const;
  virtual void print() const;
  virtual bool check() const;
protected:
  int a;
  int b;
  int c;
};


class IsoscelesTriangle:public virtual Triangle {
public:
  IsoscelesTriangle();
  virtual bool check() const;
  virtual void print() const;
};



class RightTriangle:public virtual Triangle {
public:
  RightTriangle();
  virtual bool check() const;
  virtual void print() const;
};


class IsoscelesRightTriangle:public IsoscelesTriangle, public RightTriangle {
public:
  IsoscelesRightTriangle();
  virtual bool check() const;
  virtual void print() const;
};

