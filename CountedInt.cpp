/*
 * tint.cpp
 *
 *  Created on: 2019Äê2ÔÂ2ÈÕ
 *      Author: Administrator
 */


#include<iostream>
using namespace std;

class CountedInt {
	public:
		int value;
		static int com_count;
		static int set_count;

	//redefine operator
	bool operator<(const CountedInt& b) {
		++com_count;
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

	friend ostream & operator<<(ostream & os, CountedInt b);
	friend istream & operator>>(istream & is, CountedInt b);

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

ostream & operator<<(ostream & os, CountedInt b) {
	cout << b.value;
	return os;
}

istream & operator>>(istream & is, CountedInt b) {
	cin >> b.value;
	return is;
}
