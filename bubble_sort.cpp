#include <vector>

void bubble_sort(vector<CountedInt> &v) {
	for(unsigned int i = 0;i < v.size();++i) {
		for(unsigned int j = 0;i < v.size()-1;++j) {
			if(v[j] < v[j+1])
				CountedInt::swap(v[j], v[j+1]);
		}
	}
}
