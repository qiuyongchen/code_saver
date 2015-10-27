#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
struct Node {
  char entry;
  Node *next;
  Node() {
    next = NULL;
  }
  Node(char data, Node *add_on = NULL) {
    entry = data;
    next = add_on;
  }
};
class Stack {
  public:
    Stack();
    bool empty() const;
    void push(const char item);
    void pop();
    char top() const;
    int size() const;
  protected:
    Node *top_node;
    int count;
};
#endif
