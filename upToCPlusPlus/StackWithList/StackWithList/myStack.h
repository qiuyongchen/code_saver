#include <list>;
#include <iostream>;
using namespace std;

template <class T>
class Stack {
 public:
  Stack() {}
  ~Stack() {}
  void push(T t) {
    li.push_front(t);
  }

  void pop() {
    li.pop_front();
  }

  T& top() {
    return li.front();
  }

  bool empty() {
    return li.empty();
  }

  size_t size() {
    return li.size();
  }

 private:
  list<T> li;
};
