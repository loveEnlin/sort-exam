#include"main.hpp"
using namespace std;

string Element::sort_name{"insertion_sorting "};

void Element::sort_method() {
	int j,k,i,l;
	for(j=2; j<=data.size(); j++) {
		for(k=1; k<j; k++)
			if(data[j]>data[k])break; 
		i=data[j];
		for(l=j; l>=k; l--)
			data[l]=data[l-1];
		data[k]=i;       
	}
	return 0;
}
