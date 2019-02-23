#include<iostream>
#include<vector>
using namespace std;
string Element::sort_name{"quick_sort"};
 
void quicksort(vector<int>& vec,int s,int t)
{
	int i=s,j=t;
	int tem;
	if(s<t)
	{
		tem=vec[s];
		while(i!=j)
		{
			while(j>i&&vec[j]>tem)
				j--;
			vec[i]=vec[j];
			while(i<j&&vec[i]<tem)
				i++;
			vec[j]=vec[i];
		}
		vec[i]=tem;
		quicksort(vec,s,i-1);
		quicksort(vec,i+1,t);
	}
}
int Element::sort_method()
{	
	int len = date.size();
	quicksort(date,0,date.size()-1);
	return 0;
}
