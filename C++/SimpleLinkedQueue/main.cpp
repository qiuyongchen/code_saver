#include <iostream>
#include "queue.h"
#include "card.h"
using namespace std;
 
int main() {
  
  int n = 0;
  cin >> n;
  Queue q;
  q.push(n);
  for (int i = 0; i < n; i++) {
    int x = 0;
    q.push(i);
    Card c;
    cin >> x;
    c.printCard(x);
  }
  while (!q.empty()) {
    cout << q.getFront() << endl;
    q.pop();
  }
  cout << q.getSize() << endl;

  return 0;
}
