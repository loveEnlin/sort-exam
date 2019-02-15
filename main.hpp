#ifndef __MAIN_H__
#define __MAIN_H__
#include "sorting_methods.hpp"
#include<iostream>

class Element{
public:
  bool operator<=(const Element& another){
    ++cmp_count;
    return value<=another.value;
  }

  bool operator>=(const Element& another){
    ++cmp_count;
    return value>=another.value;
  }

  bool operator=(const Element& another){
    ++set_count;
    value=another.value;
    return value;
  }

  bool operator=(const int& another){
    ++set_count;
    value=another;
    return value;
  }

  friend ostream& operator<<(ostream& os,Element& another);

  friend istream& operator>>(istream& is,Element& another);

  friend void clear();
private:
  int value;
  static long long cmp_count=0;
  static long long set_count=0;
}

ostream& operator<<(ostream& os,Element& another);
istream& operator>>(istream& is,Element& another);
void clear();
void swap();

#endif
