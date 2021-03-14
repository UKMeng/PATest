#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.length(),pos=0,exp=0;
	if(s[0]=='-') cout<<s[0];
	for(int i=0;i<len;i++)
	{
		if (s[i]=='E')
		{
			pos=i;
			break;
		}
	}
	for(int i=pos+2;i<len;i++)
		exp=exp*10+(s[i]-'0');
	if (s[pos+1]=='-')
	{
		cout<<"0.";
		for(int i=0;i<exp-1;i++)
			cout<<"0";
		cout<<s[1];
		for(int i=3;i<pos;i++)
			cout<<s[i];
	}
	else 
	{
		for(int i=1;i<pos;i++)
		{
			if(s[i]=='.') continue;
			cout<<s[i];
			if(i==exp+2&&exp<pos-3)
				cout<<".";
		}
		for(int i=0;i<exp-(pos-3);i++)
			cout<<"0";
	}
	return 0;
}