#include "abstract.h"
#include "SystemActivity.h"
#include <iostream>
#include <string>
using namespace std;

string Windows::info() {
    return "Windows QAQ";
}

string Linux::info() {
    return "Linux T_T";
}

Study::Study(System* system, string name):Activity(system,name) {
  system_ = system;
  name_ = name;
}

string Study::play() {
  string temp;
  temp += name_ + " is studing on " + system_->info();
  return temp;
}

Game::Game(System* system, string name):Activity(system,name) {
  system_ = system;
  name_ = name;
}

string Game::play() {
  string temp;
  temp += name_ + " is playing game on " + system_->info();
  return temp;
}
