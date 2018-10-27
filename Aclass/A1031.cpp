#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int len=str.length();
	int n1,n2;
	for(n2=0;n2<=len;n2++)
	{
		if((len-n2+2)%2==0)
		{
			n1=(len-n2+2)/2;
			if(n1<=n2) break;
		}
	}
	for(int i=0;i<n1-1;i++)
	{
		cout<<str[i];
		for(int j=0;j<n2-2;j++)
			cout<<" ";
		cout<<str[len-i-1]<<endl;
	}
	for(int i=0;i<n2;i++)
		cout<<str[n1-1+i];
	cout<<endl;
	return 0;
}