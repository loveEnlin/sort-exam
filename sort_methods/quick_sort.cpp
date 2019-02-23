#include "../main.hpp"
#include<iostream>
#include<vector>
using namespace std;
string Element::sort_name{"Quick Sort"};
 
void quicksort(vector<Element>& vec,int l,int r)
{
	int i=l,j=r;
	int tem;
	if(l<r)
	{
		tem=vec[(l+r)>>1].value;
		while(i<=j)
		{
			while(i<j&&vec[i].value<tem)
				i++;
			while(j>i&&vec[j].value>tem)
				j--;
			
			if(i<=j)
			{
				sawp(vec[i],vec[j]);
				i++;
				j--;
			}
		}
		vec[i].value=tem;
		if(i<r)	quicksort(vec,l,i);
		if(l>l)	quicksort(vec,j,r);
		return;
	}
}
void Element::sort_method()
{	
	int len = data.size();
	quicksort(data,0,data.size()-1);
}
