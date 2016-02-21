#include <iostream>
using namespace std;

template<class T>
class list {
 public:
    struct listelem;
    class iterator;

    // the constructor.
    list() {
        h.ptr = NULL;
        t.ptr = NULL;
        size_ = 0;
    }

    // the copy constructor.
    list(const list& x) {
        h.ptr = NULL;
        t.ptr = NULL;
        size_ = 0;
        iterator it = x.begin();

        while (it != x.end()) {
            push_back(it->data);
            it++;
        }

    }

    // the order constructor.
    list(iterator b, iterator e) {
        h.ptr = NULL;
        t.ptr = NULL;
        size_ = 0;
        iterator temp = b;

        if (e == end()) e = t;
        while (temp != e) {
            push_back(temp->data);
            temp++;
        }

    }

    // the 'same element' constructor.
    list(size_t n_elements, const T& c) {
        h.ptr = NULL;
        t.ptr = NULL;
        size_ = 0;

        for (int i = 0; i < n_elements; i++) {
            push_front(c);
        }

    }

    // the destructor.
    ~list() {
        clear();
    }

    // to get the first iterator of the list.
    iterator begin() const {
        return h;
    }

    // to get the last iterator of the list.
    iterator end() const {
        return iterator(NULL);
    }

    // to get the size of the list.
    size_t size() const {
        return size_;
    }

    // to push a new element into the list frontly.
    void push_front(const T& c) {

        // if it is the first element pushed frontly into the list.
        if (h.ptr == NULL) {
            h.ptr = t.ptr = new listelem(c);
            size_++;
        } else {
            listelem* middle = new listelem(c, h.ptr, NULL);  // initialize the
            // new listelem to insert.
            h->prev = middle;
            h.ptr = middle;
            size_++;
        }

    }

    // to push a new element into the list backly.
    void push_back(const T& c) {

        // if it is the first element pushed backly into the list.
        if (t.ptr == NULL) {
            t.ptr = h.ptr = new listelem(c);
            size_++;
        } else {
            listelem* middle = new listelem(c, NULL, t.ptr);
            t->next = middle;
            t.ptr = middle;
            size_++;
        }

    }

    // to pop an element out of the list frontly.
    void pop_front() {

        // if the head is pointing to a 'NULL' place, there is no element.
        if (h.ptr == NULL) {
            t.ptr = NULL;
        } else {
            listelem* temp = h.ptr;
            h.ptr = h->next;

            // if there is only one element in the list, and if we pop it
            // 'h.ptr' will be empty, and we can't touch 'h->prev;
            if (h.ptr != NULL)
                h->prev = NULL;
            else
                t.ptr = NULL;    // if there is no element anymore, the ta

            delete temp;    // delete    the pointer to the original header.
            size_--;
        }

    }

    // to pop an element out of the list backly.
    void pop_back() {

        // if the tail is pointing to a 'NULL' place, there is no element
        if (t.ptr == NULL) {
            h.ptr = NULL;
        } else {
            listelem* temp = t.ptr;
            t.ptr = t->prev;

            // if there is only one element leaved in the list, and we pop
            // 't.ptr' will be NULL, and we can't touch it.
            if (t.ptr != NULL) {
                t->next = NULL;
            } else {
                h.ptr = NULL;    // if there is no element anymore, the
            }
            delete temp;
            size_--;
        }

    }

    // to insert a new iterator.
    iterator insert(iterator p, const T& val) {
        listelem* temp;
        if (p != end()) {
            temp = new listelem(val, p.ptr, p->prev);
            if (p.ptr->prev != NULL) {
                p.ptr->prev->next = temp;
            } else {
                h.ptr = temp;
            }
            p->prev = temp;
        } else {
            temp = new listelem(val, NULL, t.ptr);
            t.ptr->next = temp;
            t.ptr = temp;
        }
        return iterator(temp);
    }

    // to erase a particular iterator.
    iterator erase(iterator p) {
        listelem* temp = p.ptr;
        iterator tempforreturn = ++p;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return tempforreturn;
    }

    // to determine if the list is empty.
    bool empty() const {
        return size() == 0;
    }

    // to get the first element value in the list.
    T& front() {
        return h->data;
    }

    // to get the last element value in the list.
    T& back() {
        return t->data;
    }

    // to make the list empty.
    void clear() {

        for (listelem *temp = h.ptr; temp != t.ptr;) {
            listelem *anothertemp = temp;
            temp = temp->next;
            delete anothertemp;
        }
        delete t.ptr;
        h.ptr = NULL;
        t.ptr = NULL;
        size_ = 0;
    }

    // an output overloaded function for this list class.
    friend ostream& operator<< (ostream& out, const list& x) {
        out << "[ ";

        if (x.size() != 0) {
            list<T>::listelem* temp = x.h.ptr;
            out << temp->data << " ";

            while (temp->next != NULL) {
                out << temp->next->data << " ";
                temp = temp->next;
            }

        }

        out << "]";
        return out;
    }


    // elements unit.
    struct listelem {
        T data;
        listelem *next, *prev;
        listelem(const T& s = 0, listelem* n = NULL, listelem* p = NULL) {
            // this statement is
            // equivalent to a
            // function phytotype.
            data = s;
            next = n;
            prev = p;
        }  // it needs to be implemented.
    };

    class iterator {
    public:
        friend class list;

        operator listelem* () {return ptr;}
        // overload the value type 'listelem* ', so that when
        // we pass a iterator 'it' to someplace that indeed needs
        // a 'listelem* ', the compiler can change 'it'
        // to 'it.ptr'.

        // constructor.
        explicit iterator(listelem* p = NULL) {

            if (p != NULL) {
                ptr = p;
            } else {
                ptr = NULL;
            }

        }

        // copy constructor.
        iterator(const iterator& other) {
            if (other.ptr == NULL)
                ptr = NULL;
            else
                ptr = other.ptr;
        }

        // turn to the next iterator.
        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        // turn to the last iterator.
        iterator& operator--() {
            ptr = ptr->prev;
            return *this;
        }

        iterator operator++(int a) {
            listelem tempListelem(ptr->data, ptr->next, ptr->prev);
            iterator temp(&tempListelem);  // save the original one.

            ++(*this);

            return temp;
        }

        iterator operator--(int a) {
            listelem tempListelem(ptr->data, ptr->next, ptr->prev);
            iterator temp(&tempListelem);

            --(*this);

            return temp;
        }

        listelem* operator->() {
            return ptr;
        }

        T& operator* () {
            return ptr->data;
        }

        bool operator==(const iterator& other) {
            if (other.ptr == ptr) return true;
            if (other.ptr != NULL)
                return (other.ptr->data == ptr->data &&
                other.ptr->prev == ptr->prev &&
                other.ptr->next == ptr->next);
            else return false;
        }

        bool operator!=(const iterator& other) {
            return !(*this == other);
        }
    public:
        listelem* ptr;
    };

 private:
    iterator h, t;
    size_t size_;
};

