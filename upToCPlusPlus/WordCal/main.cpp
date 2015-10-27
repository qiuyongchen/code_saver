#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char to_lower(char c) {
  if (c >= 'A' && c <= 'Z')
    c = c - 'A' + 'a';
  return c;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int position;
    string str;
    cin >> position >> str;
    str.erase(position - 1, 1);
    transform(str.begin(), str.end(), str.begin(), to_lower);
    cout << str << endl;
  }

  return 0;
}
