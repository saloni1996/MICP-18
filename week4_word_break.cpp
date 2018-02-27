#include<iostream>
#include<algorithm>
#include<string>
#include <bits/stdc++.h>
using namespace std; 

int presentDictionary(string str, string words_bag[], int size)
{
	for(int i=0;i<size;i++)
	{
		if(words_bag->compare(str)==0)
			return 1;
	}
	
	return -1;
}

int check_string(string word_dictionary[],string str, int dic_size)
{
	int len = str.length();
	if(len==0)
	 return -1;
	
	else
	{
		string temp;
		for(int i=0;i<len;i++)
		{
			temp = str.substr(0,i);
			int present=presentDictionary(temp,word_dictionary,dic_size);
			
			if(present==1 && check_string(word_dictionary,str.substr(i,len-1),dic_size))
				return 1;
		}
		return -1;
	}
	 
}

void unit_test()
{	
	string dic[]={"you","enjoy","time","with","tommy","dog"};
	int ans;
	
	ans=check_string(dic,"youyou",6);
	if(ans==-1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	
	ans= check_string(dic,"isdog",6);
	if(ans==-1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	
	ans= check_string(dic,"dogisnothere",6);
	if(ans==-1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
		
	ans=check_string(dic,"abovehigh",6);
	if(ans==-1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
		
	ans=check_string(dic," ",6);
	if(ans==-1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
}

int main()
{
	int num;
	
	cout<<"Enter the number of elements in the dictionary\n";
	cin>>num;
	
	string bag_words[num];
	string str;
	for(int i=0;i<num;i++)
	{
		cin>>bag_words[i];
	}
	
	cout<<"Enter the string which needs to be checked against the dictionary\n";
	cin>>str;
	
	int ans = check_string(bag_words,str, num);
	
	if(ans==-1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
		
		unit_test();//to test the code
	return 0;
}
