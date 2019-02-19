#include "main.hpp"

class SortingMethod{
public:
  void (*func)(std::vector<Element> v);
  std::string name;
  std::string author;
  std::string description;
};

class Element{
public:
  bool operator<=(const Element& another);
  bool operator<(const Element& another);
  bool operator>=(const Element& another);
  bool operator>(const Element& another);
  bool operator=(const Element& another);
  bool operator=(const int& another);
  friend std::ostream& operator<<(std::ostream& os,Element& another);
  friend std::istream& operator>>(std::istream& is,Element& another);
  void clear();
  static void output();
  static void swap(Element& first,Element& second);
  static bool is_sorted(std::vector<Element>& v);

  static std::vector<SortingMethod> sorting_methods;
  int value;

private:
  static long long cmp_count;
  static long long set_count;
};

std::vector<SortingMethod> Element::sorting_methods(0);
long long Element::cmp_count=0;
long long Element::set_count=0;

bool Element::operator<=(const Element& another){
  ++cmp_count;
  return value<=another.value;
}

bool Element::operator>=(const Element& another){
  ++cmp_count;
  return value>=another.value;
}

bool Element::operator<(const Element& another){
  ++cmp_count;
  return value<another.value;
}

bool Element::operator>(const Element& another){
  ++cmp_count;
  return value>another.value;
}

bool Element::operator=(const Element& another){
  ++set_count;
  value=another.value;
  return value;
}

bool Element::operator=(const int& another){
  ++set_count;
  value=another;
  return value;
}

std::ostream& operator<<(std::ostream& os,Element& another){
  os<<another.value;
  return os;
}

std::istream& operator>>(std::istream& is,Element& another){
  is>>another.value;
  return is;
}

void Element::clear(){
  cmp_count=0;
  set_count=0;
}

void Element::swap(Element& first,Element& second){
  Element third=first;
  first=second;
  second=third;
}

bool Element::is_sorted(std::vector<Element>& v) {
  std::vector<Element>::iterator i{v.begin()+1};
	while(i != v.end()){
    if(*i<*(i-1)){
      return false;
    }
  }
	return true;
}

int main(){}
