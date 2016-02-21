#include "stack.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Stack::Stack() {
  count = 0;
  top_node = NULL;
}

bool Stack::empty() const {
  return count == 0;
}

void Stack::push(const char item) {

  if (top_node == NULL) {
    Node *temp = new Node(item);
    top_node = temp;
  } else {
    Node *temp = new Node(item, top_node);
    top_node = temp;
  }

  count++;
}

void Stack::pop() {

  if (count > 0) {
    Node *temp = top_node;
    top_node = top_node->next;
    delete temp;
    count--;
  }

}

char Stack::top() const {
  if (count > 0) {
    return top_node->entry;
  } else {
    throw invalid_argument("wrong");
  }
}

int Stack::size() const {
  return count;
}

