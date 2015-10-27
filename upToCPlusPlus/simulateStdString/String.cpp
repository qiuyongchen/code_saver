#include "String.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char String::_error_sign = 0;

String::String() {
  _buff = new char[500];
  _length = 0;
  _size = 499;
}

String::String(const char *src) {
  _buff = new char[500];
  _length = 0;
  _size = 499;

  for (int i = 0; i < strlen(src); i++) {
    _buff[i] = src[i];
  }

  _length = strlen(src);
  _buff[_length] = '\0';
}

String::String(const String &src) {
  _buff = new char[500];
  _length = 0;
  _size = 499;
  (*this) = src;
}

String::~String() {
  delete []_buff;
}

void String::assign(const char *src) {
  clear();
  (*this) = src;
}

void String::append(const char &other) {
  _buff[length()] = other;
  _buff[length() + 1] = '\0';
  // be careful, don't lose it.
  _length++;
}

void String::clear() {
  for (int i = 0; i < 500; i++)
    _buff[i] = 0;
  // there is no anymore.
  _length = 0;
}

int String::compare(const String &other) const {
  string s1, s2;

  for (int i = 0; i < other.length(); i++) {
    s2 += other._buff[i];
  }
  for (int i = 0; i < length(); i++) {
    s1 += _buff[i];
  }
  if (s1.compare(s2) < 0)
    return -1;
  else if (s1.compare(s2) > 0)
    return 1;
  else
    return 0;
}

const char* String::c_str() const {
  return _buff;
}

bool String::empty() const {
  return _length == 0;
}

int String::find(const String &other, int pos) const {
  string s1, s2;
  for (int i = 0; i < other.length(); i++) {
    s2 += other._buff[i];
  }
  for (int i = pos; i < length(); i++) {
    s1 += _buff[i];
  }
  int found = s1.find(s2);
  if (found == -1) return length();
  return found;
}

int String::length() const {
  return _length;
}

String String::substr(const int &pos, const int &count) const {
  char temp[500];
  int j = 0;
  for (int i = pos; i < pos + count; i++) {
    temp[j++] = _buff[i];
  }
  temp[j] = '\0';

  String tempS(temp);
  return tempS;
}

char& String::operator[](const int &index) {
  return _buff[index];
}

void String::operator=(const String &other) {
  clear();
  for (int i = 0; i < other.length(); i++) {
    _buff[i] = other._buff[i];
  }

  _length = other.length();
  _buff[_length] = '\0';
}

void String::operator=(const char *src) {
  clear();
  for (int i = 0; i < strlen(src); i++) {
    _buff[i] = src[i];
  }

  _length = strlen(src);
  // remember that the end of the char[].
  _buff[_length] = '\0';
}

String String::operator+(const String &other) const {
  char c[500];
  int j = 0;
  for (int i = 0; i < length(); i++) {
    c[j++] = _buff[i];
  }
  for (int i = 0; i < other.length(); i++) {
    c[j++] = other._buff[i];
  }
  c[j] = '\0';
  String temp(c);
  return temp;
}

bool String::operator<(const String &other) const {
  if (_length == other._length) {
    for (int i = 0; i < _length; i++) {
      if (_buff[i] > other._buff[i])
	return false;
      if (_buff[i] < other._buff[i])
        return true;
    }
    if (!((*this) == other)) {
      return true;
    }
  } else {
    return _length < other._length;
  }

}

bool String::operator<=(const String &other) const {
  return (((*this) == other) || ((*this) < other));
}

bool String::operator>(const String &other) const {
  if (_length == other._length) {
    for (int i = 0; i < _length; i++) {
      if (_buff[i] < other._buff[i])
        return false;
      if (_buff[i] > other._buff[i])
        return true;
    }
    if (!((*this) == other)) {
      return true;
    }
  } else {
    return _length > other._length;
  }

}

bool String::operator>=(const String &other) const {
  return (((*this) == other) || ((*this) > other));
}

bool String::operator==(const String &other) const {

  if (_length == other._length) {
    for (int i = 0; i < _length; i++) {
      if (_buff[i] != other._buff[i])
        return false;
    }
    return true;
  } else {
    return false;
  }

}

bool String::operator!=(const String &other) const {
  return !(_length == other.length());
}

std::ostream& operator<<(std::ostream& out, const String &str) {
  for (int i = 0; i < str._length; i++) {
    out << str._buff[i];
  }
  return out;
}
