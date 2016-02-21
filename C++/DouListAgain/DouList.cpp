/*****************************************************************************
/* when we push, we have to be careful that if it is the first time,
/* and we have to attach each other, not just one way.
/*
/* when we pop, we have to be careful that may be it is NULL, we have to set
/* the head and the tail to be NULL. And if we pop one guy out, we should
/* change the next one's prev pointer to NULL.
*****************************************************************************/
#include "DouList.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

DouList::DouList() {
  _head = _tail = NULL;
}

DouList::DouList(const DouList &src) {
  _head = _tail = NULL;
  (*this) = src;
}

DouList::~DouList() {
  this->clear();
}

void DouList::clear() {

  while (!empty()) {
    pop_front();
  }

}

bool DouList::empty() const {
  return ((_tail == NULL) && (_head == NULL));
}

std::string DouList::to_str() const {
  string temp = "[";

  // To decide if there is ','.
  int flag = 0;

  // avoid illegal access.
  if (!empty()) {

    DouListNode *tempNode = _head;

    while (tempNode != NULL) {
      if (flag) temp += ", ";

      // change int to string.
      if (tempNode->sublist != NULL) {
	temp += tempNode->sublist->to_str();
      } else {
        stringstream ss;
        string s;
        ss << tempNode->elem;
        ss >> s;
        temp += s;
      }
      flag = 1;
      tempNode = tempNode->next;
    }

  }

  temp += "]";
  return temp;
}

DouList DouList::front() const {
  // if the _head is a DouList or not, or we have to construct a new DouList.
  if (_head->sublist != NULL) {
    DouList t(*(_head->sublist));
    return t;
  } else {
    DouList temp;
    temp.push_front(DouListNode(_head->elem));
    return temp;
  }

}

DouList DouList::back() const {
  // if the _tail is a DouList or not, or we have to construct a new DouList.
  if (_tail->sublist != NULL) {
    DouList t(*(_head->sublist));
    return t;
  } else {
    DouList temp;
    temp.push_front(DouListNode(_tail->elem));
    return temp;
  }

}

void DouList::push_front(const DouListNode &e) {
  // copy e
  DouListNode *temp = new DouListNode(e.elem, e.prev, e.next);
  if (e.sublist != NULL)
    temp->sublist = new DouList((*e.sublist));

  // be careful when it is the first time to pushfront.
  if (this->empty()) {
    _head = _tail = temp;
  } else {
    // attach the new DouListNode to the head(because two way)
    temp->next = _head;  // if e is construted by int implicitly, then
                        // temp->next is NULL.
    _head->prev = temp;
    // make the new DouListNode the head.
    _head = temp;
  }

}

void DouList::push_back(const DouListNode &e) {
  // copy e
  DouListNode *temp = new DouListNode(e.elem, e.prev, e.next);
  if (e.sublist != NULL)
    temp->sublist = new DouList((*e.sublist));

  // be careful when it is the first time to pushback.
  if (this->empty()) {
    _tail = _head = temp;
  } else {
  // attach the new DouListNode to the tail(because two way)
    temp->prev = _tail;
  _tail->next = temp;
  // make the new DouListNode the tail.
  _tail = temp;
  }

}

void DouList::pop_front() {
  DouListNode *temp = _head;

  // we have to change the _head->next->prev to NULL(because which it point
  // to will be delete)
  if (_head->next != NULL) {
    _head->next->prev = NULL;
  }

  _head = _head->next;

  // if all are poped, then head and tail will point to NULL.
  if (_head == NULL) {
    _tail = NULL;
  }

  // if the the node has a sublist, we have to delete it to avoid leaks
  if (temp->sublist != NULL) {
    delete temp->sublist;
    temp->sublist = NULL;
  }

  delete temp;
}

void DouList::pop_back() {
  DouListNode *temp = _tail;

  // we have to change the _tail->prev->next to NULL(because which it point
  // to will be delete)
  if (_tail->prev != NULL) {
    _tail->prev->next = NULL;
  }

  _tail = _tail->prev;

  // if all are poped, then head and tail will point to NULL.
  if (_tail == NULL) {
    _head = NULL;
  }

  // if the the node has a sublist, we have to delete it to avoid leaks
  if (temp->sublist != NULL) {
    delete temp->sublist;
    temp->sublist = NULL;
  }

  delete temp;
}

void DouList::operator=(const DouList &other) {
  // clear the list to avoid something fault still exit.
  clear();

  // avoid illegal access.
  if (!other.empty()) {

    DouListNode *temp = other._head;

    while (temp != NULL) {
      push_back(*temp);
      temp = temp->next;
    }

  }

}

std::ostream& operator<<(std::ostream &out, const DouList &list) {
  out << list.to_str();
  return out;
}

DouList::operator int() {
  return _head->elem;
}
