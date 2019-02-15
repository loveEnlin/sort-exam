#include "main.hpp"
using namespace std;

ostream& operator<<(ostream& os,Element& another){
  os<<another.value;
  return os;
}
istream& operator>>(istream& is,Element& another){
  is>>another.value;
  return is;
}

void clear(){
  com_count=0;
  set_count=0;
}

void swap(Element& first,Element& second){
  Element third=first;
  first=second;
  second=third;
}
