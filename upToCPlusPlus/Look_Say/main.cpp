#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
  int n;
  char redleaf;
  int wlxead;
  char str[100];
  char c;

  cin >> n;

  for (int i = 0; i < n; i++) {
    redleaf = 0;
    wlxead = 0;

    cin >> str;
    redleaf = str[0];
    wlxead = 1;

    for (int j = 1; str[j] != '\0'; j++) {

      if (str[j] == redleaf) {
        wlxead++;
      } else {
        cout << wlxead << redleaf;
        redleaf = str[j];
        wlxead = 1;
      }

    }

    cout << wlxead << redleaf << endl;

  }
  return 0;
}
