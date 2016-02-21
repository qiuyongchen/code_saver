#include "BigInteger.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

BigInteger::BigInteger() {
  data_ = new int[1000];
  for (int i = 0; i < 1000; i++)
    data_[i] = 0;
  size_ = 0;
}

BigInteger::BigInteger(const string& number) {
  data_ = new int[1000];
  for (int i = 0; i < 1000; i++)
    data_[i] = 0;
  size_ = number.length();
  int j = size_;
  for (int i = 999; j >  0; i--) {
    data_[i] = number[j - 1] - '0';
    j--;
  }
  size_ = number.length();
}

BigInteger::BigInteger(const BigInteger& other) {
  data_ = new int[1000];
  for (int i = 0; i < 1000; i++)
    data_[i] = 0;
  size_ = other.size_;
  for (int i = 0; i < 1000; i++) {
    data_[i] = other.data_[i];
  }
}

BigInteger operator+(const BigInteger& left, const BigInteger& right) {
  string str;
  int temp;
  int s[1000];
  for (int i = 0; i < 1000; i++)
    s[i] = 0;
  for (int i = 999; i > 1; i--) {
    temp = left.data_[i] + right.data_[i] + s[i];
    s[i] = temp % 10;
    s[i - 1] = temp / 10;
  }
  for (int i = 0; i < 1000; i++) {
    str += (s[i] + '0');
  }
  BigInteger bittemp(str);
  return bittemp;

}

BigInteger operator-(const BigInteger& left, const BigInteger& right) {
  string str;
 
  int s[1000];
  for (int i = 0; i < 1000; i++)
    s[i] = 0;

  int s1[1000];
  for (int i = 0; i < 1000; i++)
    s1[i] = left.data_[i];

  int s2[1000];
  for (int i = 0; i < 1000; i++)
    s2[i] = right.data_[i];

  for (int i = 999; i > 1; i--) {
    if (s1[i] >= s2[i]) {
      s[i] += s1[i] - s2[i];
    } else {
      s[i] += s1[i] - s2[i] + 10;
      s1[i - 1]--;
    }
  }
  for (int i = 0; i < 1000; i++) {
    str += (s[i] + '0');
  }
  BigInteger bittemp(str);
  return bittemp;
}

ostream& operator<<(ostream& out, const BigInteger& Bint) {
  string str;
  int i;
  for (i = 0; i < 1000; i++) {
    if (Bint.data_[i] != 0)
      break;
  }
  if (i == 1000)
    cout << 0;
  for (; i < 1000;i++)
    cout << Bint.data_[i];
  return out;
}

BigInteger:: ~BigInteger() {
  delete []data_;
}
