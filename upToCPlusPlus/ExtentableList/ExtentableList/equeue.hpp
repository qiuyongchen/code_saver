#include <queue>
#include <iostream>
using namespace std;

template<class T>
class Queue {
 public:
    queue<T> q;
    int size() {
        return q.size();
    }
    T front() {
        return q.front();
    }

    void push(T a) {
        q.push(a);
    }
    void pop() {
        q.pop();
    }
    void clear() {
        while (size() != 0) pop();
    }
        
};

/*
#include "equeue.h"
#include <iostream>
#include <string>
using namespace std;

template<class T>
Queue<T>::Queue() {
    frontBlock_ = backBlock_ = NULL;
    size_ = count_ = ptrb_ = ptrf_ = 0;
}

template<class T>
Queue<T>::~Queue() {
    clear();
}

template<class T>
void Queue<T>::clear() {
    while (!empty()) pop();
}

template<class T>
bool Queue<T>::empty() const {
    return (size() == 0);
}

template<class T>
int Queue<T>::size() const {
    return size_;
}

template<class T>
T Queue<T>::front() const {
    if (!empty())
        return frontBlock_->dat[ptrf_];
    else
        exit(1);
}

template<class T>
void Queue<T>::push(const T& a) {

    // if the queue is empty or the array is full(labeled by subscrit1024)
    // we have to append a new array to the queue.
    if (empty() || ptrb_ == 1024) {
        appendBlock();
    }

    // push the new element into the queue.
    backBlock_->dat[ptrb_++] = a;

    size_++;
}

template<class T>
T Queue<T>::pop() {

    // if the queue is empty.
    if (empty()) exit(1);

    // if there is only one element in the backBlock, then we pop it out
    // and reduce that backBlock.
    ptrf_++;
    if (ptrf_ == 1024 || (ptrf_ == ptrb_ && frontBlock_ == backBlock_))
        reduceBlock();

    size_--;
}

template<class T>
void Queue<T>::appendBlock() {
    // if the queue if empty.
    if (empty()) {
        frontBlock_ = backBlock_ = new MemBlock<T>;
        frontBlock_->prev = frontBlock_->next = NULL;
        backBlock_->prev = backBlock_->next = NULL;
    // or the queue is not empty.
    } else {
        MemBlock<T> *tempPtr = new MemBlock<T>;  // allocate a new MemBlock.
        tempPtr->next = NULL;
        tempPtr->prev = backBlock_;
        backBlock_->next = tempPtr;
        backBlock_ = tempPtr;
    }
    // set back the count_(it is the subscrit of the array dat[1024]) to zero.
    count_ = ptrb_ = 0;
}

template<class T>
void Queue<T>::reduceBlock() {
    // if the queue is empty.
    if (empty()) {
        exit(1);
    // or the queue is not empty.
    } else {
        MemBlock<T> *tempPtr = frontBlock_;
        frontBlock_ = frontBlock_->next;
        delete tempPtr;
    }
    count_ = ptrf_ = 0;  // set up the count_(subscrit of array dat[1024]) to 0
}

template<class T>
void Queue<T>::reset() {

}
*/