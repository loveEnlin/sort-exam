#include "main.hpp"
#include <fstream>
#include <cstring>
#include <iostream>
#include <random>
#include <ctime>
#include <sstream>
using namespace std;

int pow(int n) {
	int sum = 1;
	for(int i = 0;i < n;++i) {
		sum *= 2;
	}
	return sum;
}

string nameGiver(int a, int b) {
	ostringstream oss;
	oss << ".\\data\\data" << a << '-' << b << ".in";
	string name = oss.str();
	return name;
}

int main() {
	//Creat file Size_Nomber in data
	cout << "Initializing data..." << endl;
	system("md .\\data");
	for(int i = 7;i <= 17;++i) {
		int size = pow(i);
		default_random_engine e(time(0));
		uniform_int_distribution<int> ran(0, size);
		for(int j = 0;j < 20;++j) {
			string name = nameGiver(i, j);
			ofstream data_ost(name, fstream::out);
			for(int i = 0;i < size;++i) {
				data_ost << ran(e) << ' ';
			}
			cout<<"Creat " << name << endl;
			data_ost.close();
		}
	}
	cout << "Finish!";
	return 0;
}
