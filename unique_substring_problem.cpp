
#include<iostream>
#include<string>
using namespace std;

int unique_sub(string str)
{
	int len = str.length();
	int comp_len=0,cnt=0,start=0;
	
	char crnt;
	int hash[256]={0};
	
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
		return -1;
		
		crnt=str[i];
		
		if(hash[str[i]]==1)
		{
			while(str[start]!=crnt)
			{
				hash[str[start]]=0;
				++start;
				--cnt;
			}
			++start;
		}
		
		else
		{
			hash[str[i]]=1;
			++cnt;
			if(cnt>comp_len)
			comp_len=crnt;
		}
		
	}
	return comp_len;
	
	
}


int main()
{
	string str;
	cin>>str;
	int result=unique_sub(str);
	
	if(result==-1)
		cout<<"\n Invalid string";
	else
	{
		cout<<"The length of the unique substring is "<<int(result);
	}
	return 0;
}
	
