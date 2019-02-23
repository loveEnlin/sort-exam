#include <main.hpp>
using namespace std;
string Element::sort_name{"heap_sort"};
 
void Heapify(vector<int> &data, int &s, int &len){
	int fa = s;
	int child = 2*fa+1;
	while(child < len){
		if(child+1 < len && data[child] < data[child+1]){
			++child;
		}
		if(data[fa]<data[child]){
			Element::swap(data[fa], data[child]);
			fa = child;
			child = 2*fa+1;
			cout << "fa2 = " << fa <<" " << "child2 = " << child << endl;
		}
		else{
			break;
		}
	}
	printkk(data,len);
	cout << endl;
}
 
int start = 0;
 
void HeapSort(vector<int> &data, int &len){
  // initial building heap
	for(int i = (len-1)/2; i>=0;--i){
		Heapify(data, i, len);
	}
	for(int i = len-1; i>0;--i){
		swap(data[i],data[start]);
		Heapify(data, start, i);
	}
}
 
int Element::sort_method(){
{	
	int len = date.size();
	HeapSort(data, len);
}
