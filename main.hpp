#ifndef __main_hpp__
#define __main_hpp__
#include<iostream>
#include<vector>
#include<string>

const std::string data_file="./data";

class Element{
	public:
		bool operator<=(const Element& another);
		bool operator<(const Element& another);
		bool operator>=(const Element& another);
		bool operator>(const Element& another);
		bool operator=(const Element& another);
		bool operator=(const char& another);
		static void init();
		static void swap(Element& first,Element& second);
		static bool is_sorted();
		static bool input();
		static void output();
		static void sort_method();
		
		char value;
		static long long cmp_count;
		static long long set_count;
		static std::vector<Element> data;
		static long data_length;
};//The class of the numbers to replace typical datatype.

#endif
