#include<fstream>
#include<string>
#include<random>
#include<iostream>

constexpr int repeat{20};
constexpr int start_num{7};//2^7 Elements
constexpr int end_num{20};//2^17 Elements
const std::string file_name{"./data"};

int main(){
	std::default_random_engine random_generator;
	std::uniform_int_distribution<char> random_distribution(-127,127);
	std::ofstream ofs(file_name,std::ofstream::out|std::ofstream::binary|std::ofstream::trunc);
	for(int current_num{start_num};current_num<=end_num;++current_num){
		std::cout<<"Current Num:"<<current_num<<std::endl;
		for(int repeat_times{repeat};repeat_times>0;--repeat_times){
			ofs<<current_num;
			std::cout<<"Repeat:"<<repeat_times<<std::endl;
			for(long long num_id{(1<<static_cast<long long>(current_num))};num_id>0;--num_id){
				char number{random_distribution(random_generator)};
				ofs<<number;
			}
		}
	}
}
