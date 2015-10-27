/***************************************************
/* Observer pattem.
/* Created by QiuYongChen.
***************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The father of all the observers.
class Observer {
 public:
     virtual ~Observer() {}
     virtual void notify() = 0;  // get message from the subject.
};

// One oberser A.
class ObserverA : public Observer {
 public:
     void notify() {
         cout << "ObserverA is notified that Subject change." << endl;
     }
};

// Another Oberserver B.
class ObserverB : public Observer {
 public:
     void notify() {
         cout << "ObserverB is notified that Subject change." << endl;
     }
};

class Subject {
 public:
     // this function get all the infomation of its observer, so that it
     // can tell its observer that something has changed.
     void registerObserver(Observer* o) {
         observerCollection.push_back(o);
     }

     // remove its observer because sometimes its observer may be dead.
     void unregisterObserver(Observer* o) {
         for (vector<Observer*>::iterator it = observerCollection.begin();
             it != observerCollection.end(); ++it) {
                 if (*it == o) {
                     observerCollection.erase(it);
                     break;
                 }
         }
     }

     // tell all observers that something has changed, tell them to
     // do take some meansuer to protect themselves.
     void notifyObserver() {
         for (vector<Observer*>::iterator it = observerCollection.begin();
             it != observerCollection.end(); ++it) {
                 (*it)->notify();
         }
     }

 private:
     vector<Observer*> observerCollection;
};
