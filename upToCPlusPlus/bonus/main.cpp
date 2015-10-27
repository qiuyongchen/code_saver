#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  int n;
  cin >> str;
  cin >> n;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] < 97) {
      if (str[i] > n + 64)
	str[i] += 32;
    } else {
      if (str[i] <= n + 96)
	str[i] -= 32;
    }

  }
  cout << str << endl;
  return 0;
}
