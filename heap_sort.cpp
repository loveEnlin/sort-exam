#include <iostream>
#include <vector>
 
using namespace std;
string Element::sort_name{"heap_sort"};
 
// heap sorting
void Heapify(vector<int> &invec, int &s, int &len){
	int fa = s;
	int child = 2*fa+1;
	cout << "fa1 = " << fa <<" " << "child1 = " << child << endl;
	while(child < len){
		if(child+1 < len && invec[child] < invec[child+1]){
			++child;
		}
		if(invec[fa]<invec[child]){
			Element::swap(invec[fa], invec[child]);
			fa = child;
			child = 2*fa+1;
			cout << "fa2 = " << fa <<" " << "child2 = " << child << endl;
		}
		else{
			break;
		}
	}
	printkk(invec,len);
	cout << endl;
}
 
int start = 0;
 
void HeapSort(vector<int> &invec, int &len){
  // initial building heap
	for(int i = (len-1)/2; i>=0;--i){
		Heapify(invec, i, len);
	}
	for(int i = len-1; i>0;--i){
		swap(invec[i],invec[start]);
		Heapify(invec, start, i);
	}
}
 
int Element::sort_method(){
{	
	int len = date.size();
	HeapSort(invec, len);
}