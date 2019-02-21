#ifndef __main_hpp__
#define __main_hpp__
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

const std::string data_file{"./data"};
const std::string log_file{"./log.md"};

class Element{
	public:
		bool operator<=(const Element& another);
		bool operator<(const Element& another);
		bool operator>=(const Element& another);
		bool operator>(const Element& another);
		bool operator=(const Element& another);
		bool operator=(const char& another);
		static void init();//To clear the data and initialize it.
		static void swap(Element& first,Element& second);//To swap two Elements.
		static bool is_sorted();
		static bool input();
		static void output();
		static void sort_method();
		
		char value;
		static int times;
		static long long cmp_count;
		static long long set_count;
		static std::vector<Element> data;
		static int data_length;
		static std::string sort_name;
		static std::ifstream ifs;
};//The class of the numbers to replace typical datatype.

#endif
