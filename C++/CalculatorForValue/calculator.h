#include <sstream>
#include <stack>
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Calculator {
 public:
  // determinine if the character is a operator.
  int isOperator(int a) {
    if (a == '+' * -1 || a == '-' * -1 || a == '*' * -1 || a == '/' * -1
    || a == '(' * -1 || a == ')' * -1)
      return true;
    else
      return false;
  }

  // flag == true means that the operator is in the stack.
  int prec(char a, bool flag) {
    if (a == '+' * -1 || a == '-' * -1)
      return 1;
    else if (a == '*' * -1 || a == '/' * -1)
      return 2;
    else if ((a == '(' * -1 || a == ')' * -1) && flag)
      return 0;
    else if ((a == '(' * -1 || a == ')' * -1) && !flag)
      return 3;
    else
      return -1;
  }

  int getResult(char* str_char) {
    string str;
    vector<int> storeExp;
    list<int> v;
    stack<char> sta;
    int len = 0;

    for (int i = 0; str_char[i] != '\0'; ++i) {
      str += str_char[i];
    }

    while (!str.empty()) {
      int i = 0;

      // get the position of the operator
      while (!isOperator(str[i] * -1) && str[i] != '\0') ++i;

      if (i != 0) {
      // get the substr before that operator
      string strTemp = str.substr(0, i);

      // change the substr to int
      int temp;
      stringstream ss;
      ss << strTemp;
      ss >> temp;

      // push the int to vector
      storeExp.push_back(temp);
      }

      // push the operator to vector, if we meet the '\0' then terminate
      if (str[i] != '\0')
	storeExp.push_back(str[i] * -1);
      else
        break;

      // cut out the part has been pushed into vector
      str = str.substr(i + 1);

    }

    for (int i = 0; i < storeExp.size(); ++i) {

      // if the character is not a operator, just output it.
      if (!isOperator(storeExp[i])) {
        v.push_back(storeExp[i]);

    // or it is a operator.
      } else {

    // if the stack is empty(at least at first), we just have to push
    // the operator in without thinking about anything else.
    if (sta.empty()) {
      sta.push(storeExp[i]);

    // or it is not empty.
    } else {

      // if we meet '('.
      if ((storeExp[i]) == ('(' * -1)) {
        sta.push(storeExp[i]);

      // if we meet ')'.
      } else if ((storeExp[i]) == (')' * -1)) {

        // out put all the operator until we meet '('.
        while (sta.top() != ('(' * -1)) {
          v.push_back(sta.top());
          sta.pop();
        }

        // pop out '('.
        sta.pop();

      // if we meet other operators('+' '-' '*' '/').
      } else if (isOperator(storeExp[i])) {

        // warning! the '(' and ')' which are in stack has lowest prec
        // than other, it will not be poped out until no other operator
        // that can be poped out in the stack.
        while (!sta.empty() && (prec((storeExp[i]), false) <= prec(sta.top(),
                                true))) {
          v.push_back(sta.top());
          sta.pop();
        }

        // push in that operator.
        sta.push(storeExp[i]);
      }
    }
      }
    }

    // pop out all the operator in stack
    while (!sta.empty()) {
      v.push_back(sta.top());
      sta.pop();
    }

    // calculator the result
    while (v.size() > 2) {

      for (list<int>::iterator it = v.begin(); it != v.end(); ++it) {

    if (isOperator(*it)) {
      list<int>::iterator b = it, e = it;
      --e;
      --b;
      --b;

      if ((*it) == '+' * -1) {
        (*it) = (*b) + (*e);
      }
      else if ((*it) == '-' * -1)
        (*it) = (*b) - (*e);
      else if ((*it) == '*' * -1)
        (*it) = (*b) * (*e);
      else if ((*it) == '/' * -1)
        (*it) = (*b) / (*e);

      b = v.erase(b);
      v.erase(b);

      break;
    }
      }
    }
    //    cout << v.front() << endl;
    return v.front();
  }
};
