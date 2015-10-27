#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<class T>
class list {
 public:
  struct listelem;
  class iterator;

  list() {
    h.ptr = t.ptr = 0;
  }

  list(size_t n_elements, const T& c);
  list(const list& x);
  list(iterator b, iterator e);

  ~list() {
    clear();
  }

  iterator begin() const;
  iterator end() const;

  size_t size();

  void push_front(const T& c);
  void push_back(const T& c);
  void pop_front();
  void pop_back();

  iterator insert(iterator position, const T& val);
  iterator erase(iterator position);

  bool empty() const {
    return (h.ptr == t.ptr == NULL);
  }

  T& front();
  T& back();

  void clear() {
    while (!empty()) pop_back();
  }

  friend ostream& operator<<(ostream &out, const list& x);

  struct listelem {
    T data;
    listelem *next, *prev;
    listelem(const T& s, listelem* n, listelem* p) {
      data = s;
      next = n;
      prev = p;
    }
  };

  class  iterator {
  public:
    friend class list;
    explicit iterator(listelem* p = 0);

    iterator(const listelem& other);

    iterator& operator++();
    iterator& operator--();
    iterator operator++(int argument);
    iterator operator--(int argument);
    listelem* operator->();
    T& operator*();

    operator listelem* () {return ptr;}

  private:
    listelem* ptr;
  };

 private:
  iterator h, t;
};
