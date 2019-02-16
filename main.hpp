#ifndef __main_hpp__
#define __main_hpp__
#include<iostream>
#include<vector>
#include<string>

class SortingMethod;
class Element;

std::ostream& operator<<(std::ostream& os,Element& another);
std::istream& operator>>(std::istream& is,Element& another);

#endif
