#include<iostream>
#include<random>
#include<ctime>
#include<fstream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

//declear CountedInt
class CountedInt {
	public:
		int value;
		static int com_count;
		static int set_count;

	//redefine operator
	bool operator<(const CountedInt& b) {
		++com_count;
		cout << 'a';
		return this->value < b.value;
	}

	bool operator>(const CountedInt& b) {
		++com_count;
		return this->value > b.value;
	}

	bool operator<=(const CountedInt& b) {
		++com_count;
		return this->value <= b.value;
	}

	bool operator>=(const CountedInt& b) {
		++com_count;
		return this->value >= b.value;
	}

	bool operator!=(const CountedInt& b) {
		++com_count;
		return this->value != b.value;
	}

	bool operator==(const CountedInt& b) {
		++com_count;
		return this->value == b.value;
	}

	void operator=(const CountedInt& b) {
		++set_count;
		this->value = b.value;
	}

	void operator=(const int& b) {
		++set_count;
		this->value = b;
	}

	friend ostream & operator<<(ostream & os, CountedInt b) {
		cout << b.value;
		return os;
	}

	friend istream & operator>>(istream & is, CountedInt b) {
		cin >> b.value;
		return is;
	}

	//main function
	static void swap(CountedInt& a, CountedInt& b) {
		int t = a.value;
		a.value = b.value;
		b.value = t;
		set_count += 2;
	}

	static void clear_counter() {
		com_count = 0;
		set_count = 0;
	}
};

int CountedInt::com_count = 0;
int CountedInt::set_count = 0;

void print(vector<CountedInt>& v) {
	for(int i = 0;i < v.size();++i) {
		cout << v[i].value << ' ';
	}
}

bool is_sorted(vector<CountedInt> v) {
	for(int i = 0; i < v.size() -1; ++i) {
		if(v[i] > v[i+1])
			return false;
	}
	return true;
}

string nameGiver(int a, int b) {
	string name = ".\\data\\data";
	name += a +'0';
	name += '-';
	name += b + '0';
	name += ".in";
	return name;
}

//----------------------Sort Function------------------------
void bubble_sort(vector<CountedInt> &v) {
	for(int i = 0;i < v.size();++i) {
		for(int j = 0;i < v.size()-1;++j) {
			if(v[j] > v[j+1])
				CountedInt::swap(v[j], v[j+1]);
		}
	}
}

//-----------------------------------------------------------

int main() {
	//initialize process
	int process1 = 0;
	int process2 = 2;
	int process3 = 0;
	ifstream pist("process.txt");
	pist >> process1 >> process2 >> process3;

	//debuger
	/*
	cout << "reintit?(y/n)";
	char reinit;
	cin >> reinit;
	if(reinit == 'y') {
		process1 = 0;
		process2 = 2;
		process3 = 0;
	}
	*/

	//random initialize and save the data if haven't done
	//Creat file Size_Nomber in data
	ofstream data_ost(".\\data\\temp");
	if(!data_ost) {
		cout << "Initializing data..." << endl;
		data_ost.close();
		system("md .\\data");
		for(int i = 2;i <= 7;++i) {
			int size = pow(10, i);
			default_random_engine e(time(0));
			uniform_int_distribution<int> ran(0, size);
			for(int j = 0;j < 10;++j) {
				string name = nameGiver(i, j);
				data_ost.open(name, fstream::out);
				for(int i = 0;i < size;++i) {
					data_ost << ran(e) << ' ';
				}
				cout<<"Creat " << name << endl;
				data_ost.close();
			}
		}
	}

	//Sort Test
	ifstream data_ist;
	ofstream result_ost;
	ofstream post("process.txt");
	while(process1 != 6) {
		//break;
		//No break between cases!
		switch(process1) {
			case 0:
				cout << "Working on bubble_sort:" << endl;
				result_ost.open("bubble_sort_result.txt", fstream::app);
				for(int i = process2;i <= 7;++i) {
					int size = pow(10, i) + 1;
					result_ost << "Size: " << size << endl;
					for(int j = process3;j < 10;++j) {
						//Creat vector v
						string name = nameGiver(i, j);
						data_ist.open(name);
						vector<CountedInt> v(size);
						for(int k = 0;k < size;++k) {
							data_ist >> v[k];
						}
						bubble_sort(v);
						if(is_sorted(v)) {
							result_ost << "    " << j << ": "
								<<"com_count " << CountedInt::com_count
								<<"set_count " << CountedInt::set_count << endl;
						}else{
							cout << "SortedError";
						}
						CountedInt::clear_counter();
						data_ist.close();
						post << 0 << i << j;
						cout << "process: " << 0 << i << j << endl;
					}
				}
				result_ost.close();
				++process1;
				post << "1 2 0";
			case 1:
				cout << "Working on selection_sort:" << endl;
				++process1;
			case 2:
				cout << "Working on insertion_sort:"<< endl;
				++process1;
			case 3:
				cout << "Working on merge_sort:"<< endl;
				++process1;
			case 4:
				cout << "Working on quick_sort:" << endl;
				++process1;
			case 5:
				cout << "Working on heap_sort:" << endl;
				++process1;
		}
	}
	cin.ignore();
	return 0;
}
