#include "match.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool Match::isMatch(char *s) {
  Stack birdMan;
  birdMan.push(s[0]);
  for (int i = 1; i < strlen(s); i++) {
    if (birdMan.top() == '[' && s[i] == ']')
      birdMan.pop();
    else if(birdMan.top() == '{' && s[i] == '}')
      birdMan.pop();
    else if(birdMan.top() == '(' && s[i] == ')')
      birdMan.pop();
    else
      birdMan.push(s[i]);
  }

  if (birdMan.isEmpty())
    return true;
  else
    return false;
}
