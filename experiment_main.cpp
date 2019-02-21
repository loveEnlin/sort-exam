#include "experiment_main.hpp"

long long Element::cmp_count{0};
long long Element::set_count{0};
std::ifstream Element::ifs(data_file,std::ifstream::in|std::ifstream::binary);
std::vector<Element> Element::data;
int Element::data_length{0};
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
	ifs>>data_length;
	if(data_length==0) return false;
	for(int i{data_length};i>0;--i){
		char x;
		ifs>>x;
		Element tmp;
		tmp=x;
		data.push_back(tmp);
	}
	return true;
}

void Element::output(){
	std::ofstream ofs(log_file, std::ofstream::out|std::ios::ate);
	ofs<<'|'<<sort_name<<'|'<<times<<'|'<<"2<sup>"<<data_length<<"</sup>"<<'|'<<cmp_count<<'|'<<set_count<<'|';
	ofs.close();
}

int main(){
	while(Element::input()){
		Element::sort_method();
		if(!Element::is_sorted()) std::cout<<"Error! Times:"<<Element::times;
		Element::output();
	}
	return 0;
}
