#ifndef __main_hpp__
#define __main_hpp__
#include<iostream>
#include<vector>
#include<string>

constexpr std::string data_file{"./data"};

class Element{
	public:
		bool operator<=(const Element& another);
		bool operator<(const Element& another);
		bool operator>=(const Element& another);
		bool operator>(const Element& another);
		bool operator=(const Element& another);
		bool operator=(const int& another);
		void clear();
		static void swap(Element& first,Element& second);
		static bool is_sorted(std::vector<Element>& v);
		
		char value;
		static long long cmp_count;
		static long long set_count;
};//The class of the numbers to replace typical datatype.

#endif
