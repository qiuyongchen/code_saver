#include "abstract.h"
#include <iostream>
#include <string>
using namespace std;

class Windows:public System {
 public:
  Windows() {}
  virtual string info();
};

class Linux:public System {
 public:
  Linux() {}
  virtual string info();
};

class Study:public Activity {
 public:
  Study(System* system, string name);
  ~Study() {}
  virtual string play();
};

class Game:public Activity {
 public:
  Game(System* system, string name);
  ~Game() {}
  virtual string play();
};
