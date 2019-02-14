#include<iostream>
#include<random>
#include<ctime>
#include<fstream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;


//declare CountedInt
class CountedInt {
	public:
		int value;
		static long long com_count;
		static long long set_count;

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

	friend ostream & operator<<(ostream & os, CountedInt& b) {
		os << b.value;
		return os;
	}

	friend istream & operator>>(istream & is, CountedInt& b) {
		is >> b.value;
		return is;
	}

	//main function
	static void swap(CountedInt& a, CountedInt& b) {
		int t = a.value;
		a.value = b.value;
		b.value = t;
		set_count += 3;
	}

	static void clear_counter() {
		com_count = 0;
		set_count = 0;
	}
};

long long CountedInt::com_count = 0;
long long CountedInt::set_count = 0;

//----------------------Sort Function------------------------
void bubble_sort(vector<CountedInt> &v) {
	for(int i = 0;i < v.size();++i) {
		for(int j = 0;j < v.size()-1 ;++j) {
			if(v[j] > v[j+1])
				CountedInt::swap(v[j], v[j+1]);
		}
	}
}

void selection_sort(vector<CountedInt> &v) {

}

void insertion_sort(vector<CountedInt> &v) {

}

void merge_sort(vector<CountedInt> &v) {

}

void quick_sort(vector<CountedInt> &v) {

}

void heap_sort(vector<CountedInt> &v) {

}
//-----------------------------------------------------------


//basic function
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

int pow(int n) {
	int sum = 1;
	for(int i = 0;i < n;++i) {
		sum *= 10;
	}
	return sum;
}

//function for beauty
string nameGiver(int a, int b) {
	string name = ".\\data\\data";
	name += a +'0';
	name += '-';
	name += b + '0';
	name += ".in";
	return name;
}

void mainTester(int p1, int p2, int p3, ofstream& rost) {
	ofstream post("process.txt");
	for(int i = p2;i <= 7;++i) {
		int size = pow(i);
		if(p3 == 0)
			rost << "Size: " << size << endl;
		for(int j = p3;j < 10;++j) {
			//Creat vector v
			string name = nameGiver(i, j);
			cout << name << " Load--";
			ifstream data_ist(name);
			vector<CountedInt> v(size);
			for(int k = 0;k < size;++k) {
				data_ist >> v[k];
			}
			//Maybe I will be able to use function object next time...
			switch(p1) {
				case 0: bubble_sort(v);
						break;
				case 1: selection_sort(v);
						break;
				case 2: insertion_sort(v);
						break;
				case 3: merge_sort(v);
						break;
				case 4: quick_sort(v);
						break;
				case 5: heap_sort(v);
						break;
			}
			if(is_sorted(v)) {
				rost << "    " << j << ": "
					<<" com_count " << CountedInt::com_count
					<<" set_count " << CountedInt::set_count << endl;
			}else{
				cerr << "SortedError";
			}
			CountedInt::clear_counter();
			data_ist.close();
			post.clear();
			post.seekp(0);
			post << p1 << ' ' <<  i << ' ' << j;
			cout << "process: " << p1 << i << j << endl;
		}
	}
	post.clear();
	post.seekp(0);
	post << p1 << " 2 0";
}

int main() {
	//initialize process
	int process1 = 0;
	int process2 = 2;
	int process3 = 0;
	ifstream pist("process.txt");
	pist >> process1 >> process2 >> process3;

	//random initialize and save the data if haven't done
	//Creat file Size_Nomber in data
	ofstream data_ost(".\\data\\temp");
	if(!data_ost) {
		cout << "Initializing data..." << endl;
		data_ost.close();
		system("md .\\data");
		for(int i = 2;i <= 7;++i) {
			int size = pow(i);
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
	ofstream result_ost;
	while(process1 < 6) {
		//No break between cases!
		switch(process1) {
			case 0:
				cout << "Working on bubble_sort:" << endl;
				result_ost.open("bubble_sort_result.txt", fstream::app);
				mainTester(process1, process2, process3, result_ost);
				result_ost.close();
				++process1;
			case 1:
				cout << "Working on selection_sort:" << endl;
				result_ost.open("selection_sort_result.txt", fstream::app);
				mainTester(process1, process2, process3, result_ost);
				result_ost.close();
				++process1;
			case 2:
				cout << "Working on insertion_sort:"<< endl;
				result_ost.open("insertion_sort.txt", fstream::app);
				mainTester(process1, process2, process3, result_ost);
				result_ost.close();
				++process1;
			case 3:
				cout << "Working on merge_sort:"<< endl;
				result_ost.open("merge_sort.txt", fstream::app);
				mainTester(process1, process2, process3, result_ost);
				result_ost.close();
				++process1;
			case 4:
				cout << "Working on quick_sort:" << endl;
				result_ost.open("quick_sort.txt", fstream::app);
				mainTester(process1, process2, process3, result_ost);
				result_ost.close();
				++process1;
			case 5:
				cout << "Working on heap_sort:" << endl;
				result_ost.open("heap_sort.txt", fstream::app);
				mainTester(process1, process2, process3, result_ost);
				result_ost.close();
				++process1;
		}
	}
	ofstream post("process.txt");
	post << "6 0 0";
	cout << "Finish!";
	cin.ignore();
	return 0;
}
