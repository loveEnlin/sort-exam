#include "../main.hpp"
#include<iostream>
#include<vector>
using namespace std;
string Element::sort_name{"Quick Sort"};
 
void quicksort(vector<Element>& vec,int s,int t)
{
	int i=s,j=t;
	int tem;
	if(s<t)
	{
		tem=vec[s].value;
		while(i!=j)
		{
			while(j>i&&vec[j].value>tem)
				j--;
			vec[i]=vec[j];
			while(i<j&&vec[i].value<tem)
				i++;
			vec[j]=vec[i];
		}
		vec[i].value=tem;
		quicksort(vec,s,i-1);
		quicksort(vec,i+1,t);
	}
}
void Element::sort_method()
{	
	int len = data.size();
	quicksort(data,0,data.size()-1);
}
