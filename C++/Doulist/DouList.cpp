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

int DouList::_error_sign = 1;

DouList::DouList() {
  m_head = m_tail = NULL;
}

DouList::DouList(const DouList &src) {

  m_head = m_tail = NULL;
  DouListNode *temp = src.m_head;

  while (temp != NULL) {
    push_back(temp->elem);
    temp = temp->next;
  }

}

DouList::~DouList() {

  while (!empty()) {
    pop_front();
  }

}

void DouList::clear() {

  while (!empty()) {
    pop_front();
  }

}

bool DouList::empty() const {
  return ((m_tail == NULL) && (m_head == NULL));
}

std::string DouList::to_str() const {
  string temp = "[";

  // To decide if there is ','.
  int flag = 0;

  // avoid illegal access.
  if (!empty()) {

    DouListNode *tempNode = m_head;

    while (tempNode != NULL) {
      if (flag) temp += ", ";

      // change int to string.
      stringstream ss;
      string s;
      ss << tempNode->elem;
      ss >> s;
      temp += s;
      flag = 1;
      tempNode = tempNode->next;
    }

  }

  temp += "]";
  return temp;
}

int DouList::front() const {
  return m_head->elem;
}

int DouList::back() const {
  return m_tail->elem;
}

void DouList::push_front(const int &e) {
  // new a new DouListNode.
  DouListNode *tempNull = NULL;
  DouListNode *temp = new DouListNode(e, tempNull, m_head);

  // be careful when it is the first time to pushfront.
  if (m_tail == NULL && m_head == NULL) {
    m_head = temp;
    m_tail = temp;
  } else {
    // attach the new DouListNode to the head(because two way)
    m_head->prev = temp;
    // make the new DouListNode the head.
    m_head = temp;
  }

}

void DouList::push_back(const int &e) {
  // new a new DouListNode.
  DouListNode *tempNull = NULL;
  DouListNode *temp = new DouListNode(e, m_tail, tempNull);

  // be careful when it is the first time to pushback.
  if (m_head == NULL && m_tail == NULL) {
    m_tail = temp;
    m_head = temp;
  } else {
  // attach the new DouListNode to the tail(because two way)
  m_tail->next = temp;
  // make the new DouListNode the tail.
  m_tail = temp;
  }

}

void DouList::pop_front() {
  DouListNode *temp = m_head;

  // we have to change the m_head->next->prev to NULL(because which it point
  // to will be delete)
  if (m_head->next != NULL) {
    m_head->next->prev = NULL;
  }

  m_head = m_head->next;

  // if all are poped, then head and tail will point to NULL.
  if (m_head == NULL) {
    m_tail = NULL;
  }

  delete temp;
}

void DouList::pop_back() {
  DouListNode *temp = m_tail;

  // we have to change the m_tail->prev->next to NULL(because which it point
  // to will be delete)
  if (m_tail->prev != NULL) {
    m_tail->prev->next = NULL;
  }

  m_tail = m_tail->prev;

  // if all are poped, then head and tail will point to NULL.
  if (m_tail == NULL) {
    m_head = NULL;
  }


  delete temp;
}

void DouList::operator=(const DouList &other) {
  // clear the list to avoid something fault.
  clear();

  // avoid illegal access.
  if (!other.empty()) {

    DouListNode *temp = other.m_head;

    while (temp != NULL) {
      push_back(temp->elem);
      temp = temp->next;
    }

  }

}

std::ostream& operator<<(std::ostream &out, const DouList &list) {
  out << list.to_str();
  return out;
}
