#include "main.hpp"

long long Element::cmp_count{0};
long long Element::set_count{0};
std::vector<Element> Element::data;
long Element::data_length{0};
int Element::times{0};

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

bool Element::operator=(const char& another){
	++set_count;
	value=another;
	return value;
}

void Element::init(){
	cmp_count=0;
	set_count=0;
	data.clear();
	data_length=0;
}

void Element::swap(Element& first,Element& second){
	Element third=first;
	first=second;
	second=third;
}

bool Element::is_sorted() {
	std::vector<Element>::iterator i{data.begin()+1};
	while(i != data.end()){
		if(*i<*(i-1)){
			return false;
		}
	}
	return true;
}

bool Element::input(){
	++times;
	return false;
}

void Element::output(){
	std::ofstream ofs(log_file, std::ofstream::out|std::ios::ate);
	ofs<<'|'<<sort_name<<'|'<<times<<'|'<<"2<sup>"<<data_length<<"</sup>"<<'|'<<cmp_count<<'|'<<set_count<<'|';
	ofs.close();
}

int main(){
	while(Element::input()){
		Element::sort_method();
		if(!Element::is_sorted()) cout<<"Error! Times:"<<times;
		Element::output();
	}
	return 0;
}
