#include "sorters.h"
#include<iostream>
#include<random>
#include<ctime>
#include<fstream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

int CountedInt::com_count = 0;
int CountedInt::set_count = 0;

void print(vector<Tint>& v) {
	for(unsigned int i = 0;i < v.size();++i) {
		cout << v[i].value << ' ';
	}
}

bool is_sorted(vector<Tint> v) {
	for(unsigned int i = 0; i < v.size() -1; ++i) {
		if(v[i] > v[i+1])
			return false;
	}
	return true;
}

int main() {
	//debuger
	cout << "reinit?(y/n)";
	char in;
	cin >> in;
	if(in == 'y'){
		ofstream ost("process.txt");
		ost << "0 0 0";
	}

	//initialize process
	int process1 = 0;
	int process2 = 0;
	int process3 = 0;
	ifstream pist("process.txt");
	pist >> process1 >> process2 >> process3;

	//random initialize and save the data
	ofstream data_ost(".\\data\\temp");
	if(!data_ost) {
		cout << "Initializing data..." << endl;
		data_ost.close();
		system("md .\\data");
		for(int i = 2;i <= 7;++i) {
			int size = pow(10, i);
			default_random_engine e(time(0));
			uniform_int_distribution<int> ran(0, size);
			for(int j = 1;j <= 10;++j) {
				string name = ".\\data\\data";
				name += i +'0';
				name += '-';
				if(j != 10)
					name += j + '0';
				else
					name += "10";
				name += ".in";
				data_ost.open(name, fstream::out);
				for(int i = 0;i < size;++i) {
					data_ost << ran(e) << ' ';
				}
				cout<<"Creat " << name << endl;
				data_ost.close();
			}
		}
	}

	//Sort
	while(true) {
		break;
		//No break between cases!
		switch(process1) {
			case 0:
				cout << "Working on bubble_sort:";
				for(int i = process2;i < 10;++i) {
					for(int j = process3;i < 10;++i) {

					}
				}
			case 1:
				cout << "Working on selection_sort:";
				switch(process2) {

				}
			case 2:
				cout << "Working on insertion_sort:";
				switch(process2) {

				}
			case 3:
				cout << "Working on merge_sort:";
				switch(process2) {

				}
			case 4:
				cout << "Working on quick_sort:";
				switch(process2) {

				}
			case 5:
				cout << "Working on heap_sort:";
				switch(process2) {

				}
		}
	}
	cin.ignore();
	return 0;
}
