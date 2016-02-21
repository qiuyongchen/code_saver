#include "queue.h"
#include <iostream>
using namespace std;
 
Queue::Queue() {
  front = NULL;
  rear = NULL;
  count = 0;
}

bool Queue::empty() const {
  return count == 0;
}

// push an entry into the queue.
void Queue::push(const int item) {
  Node *nn = new Node();
  nn->data = item;
  if (rear == NULL) {
    front = rear = nn; // 'front' and 'rear' are in the same locate 
                       // of the memory when they are initialize.
                       // remember that we can't assign the ‘NULL rear’ to
                       // 'front', if we do so, front will point to to nowhere.
  } else {
    rear->next = nn; // attach the new node to the queue.
    rear = nn; // change the 'rear' to point to 'nn'.
  }

  count++; // count.
}

int Queue::getFront() {
  return front->data;
}
 
void Queue::pop() {
  Node *temp = front;
  front = front->next;
  delete temp;
  count--;
}
 
int Queue::getSize() {
  return count;
}
