#include "../main.hpp"
using namespace std;

string Element::sort_name{"Selection Sort"};

void Element::sort_method() {
	int j,k,i,m=-1000;
	for(j=1; j<=data.size(); j++) {
		for(k=j;k<=data.size();k++){
			if(m<[data[k]]){
				m=data[k];i=k;
			}
		}
		swap(data[j],data[i]);
	}
	return 0;
}
