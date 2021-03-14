#include <iostream>
#include <cstring>
using namespace std;
const long N = 1000000007;
int main()
{
	string test;
	cin>>test;
	int len=test.length(),countt=0,countp=0,result=0;
	for (int i=0;i<len;i++)
	{
		if(test[i]=='T')
			countt++;
	}
	for (int i=0;i<len;i++)
	{
		if(test[i]=='P') countp++;
		if(test[i]=='T') countt--;
		if(test[i]=='A') result=(result+(countp*countt)%N)%N;
	}
	cout<<result<<endl;
}