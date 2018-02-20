#include<iostream>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h>
using namespace std; 

void calculate_triplet(int* array, int size)
{
	
	
	int j,k,num1,num2,num3;
	map<int,int> triplets_hash;
	map<int,int>:: iterator tri_itr1;
	map<int,int>:: iterator tri_itr2;
	map<int,int>:: iterator tri_itr3;
	std::sort(array,array + size); //takes a nlogn complexity
	
	for(int i=0;i<size;i++)//Takes n^2 complexity
	{
		num1 = array[i];
		j=i+1;
		k=size-1;
		
		while(j<k)
		{
			if(num1+array[j]+array[k]==0)
			{
				num2 = array[j];
				num3 = array[k];
				tri_itr1 = triplets_hash.find(num1);
				tri_itr2 = triplets_hash.find(num2);
				tri_itr3 = triplets_hash.find(num3);
				if( tri_itr1==triplets_hash.end()||tri_itr2==triplets_hash.end()||tri_itr2==triplets_hash.end())
				{
					triplets_hash[num1]++;
					triplets_hash[num2]++;
					triplets_hash[num3]++;
					
					cout<<"("<<num1<<","<<num2<<","<<num3<<")\n";
				}
				else
				{
					//cout<<"Pair exist\n"<<array[k]<<array[j]<<num1;
					break;
				}
			}
			//cout<<array[j]<<array[k]<<num1<<"  \n";
			
			if(num1+array[j]+array[k]>0)
				k-=1;
			
			else
				j+=1;
						
		}
		
	}
	return;
}

int main()
{
	int num;
	
	cout<<"Enter the number of elements in the array";
	cin>>num;
	
	int* num_array = new int[num];
	
	if(num<3)
		{
			cout<<"The triplets cannot be formed";
			return 0;
		}
	
	cout<<"Enter the array";
	
	for(int i=0;i<num;i++)
		{
			cin>>num_array[i];
		}
	
	calculate_triplet(num_array,num);
	
	
	return 0;
}
