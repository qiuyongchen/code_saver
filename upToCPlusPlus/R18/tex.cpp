#include <iostream>
using namespace std;

 class singleton1_t 
 { 
 public: 
     static singleton1_t *instance () 
     { 
         if (0 == p_instance_) { 
             static singleton1_t instance; 
             p_instance_ = &instance; 
         } 
         return p_instance_; 
     } 
 
     void count_increase () {count_ ++;} 
     int count () const {return count_;} 
 
 private: 
     singleton1_t (): count_ (0) {} 
     ~singleton1_t () {} 
 
     static singleton1_t *p_instance_; 
     int count_; 
 }; 

int main() {
  singleton1_t::instance();
  return 0;
}
