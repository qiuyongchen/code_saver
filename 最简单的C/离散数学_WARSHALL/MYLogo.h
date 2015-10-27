#include <iostream>
#include <string>
using namespace std;

class MYLogo {
 public:
 void out();
};

void MYLogo::out() {
  string f = "#####                            #####";
  string s = "#                                #";
  string t = "#                                #";
  string fo ="##### #   # ##### ##### # ###    ##### ##### ##### #     #";
  string fifth = "    # #   # #   # ##### ##           # #   # #   # #  #  #";
  string sixth = "    # #   # #   # #     #            # #   # #   #  ## ##";
  string seventh = "##### ##### ##### ##### #        ##### #   # #####   # #";
  string eighth = "            #";
  string ninth = "            #";

  cout << f << endl;
  cout << s << endl;
  cout << t << endl;
  cout << fo << endl;
  cout << fifth << endl;
  cout << sixth << endl;
  cout << seventh << endl;
  cout << eighth << endl;
  cout << ninth << endl;
}
