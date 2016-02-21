#include "queue.h"
#include "card.h"
#include <queue>
#include <iostream>
using namespace std;
 
void Card::printCard(int x) {
  if (x == 1) {
    cout << "1 ";
  } else {
    Queue myqueue;
 
    for (int i = 1; i <= x; i++) {
      myqueue.push(i);
    }
 
    while (myqueue.getSize() > 2) {
      cout << myqueue.getFront() << " ";
      myqueue.pop();
      myqueue.push(myqueue.getFront());
      myqueue.pop();
 
    }
 
    cout << myqueue.getFront() << " ";
    myqueue.pop();
 
    cout << myqueue.getFront() << " ";
    myqueue.pop();
 
  }
  cout << endl;
}
