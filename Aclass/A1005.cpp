#include <iostream>
#include <cstring>
using namespace std;
string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
	string snum;
	cin>>snum;
	int sum=0,len=snum.length();
	for(int i=0;i<len;i++)
		sum+=snum[i]-'0';
	string sum_str=to_string(sum);
	int len2=sum_str.length();
	for(int i=0;i<len2;i++)
	{
		cout<<num[sum_str[i]-'0'];
		if(i!=len2-1)
			cout<<" ";
	}
	return 0;
}