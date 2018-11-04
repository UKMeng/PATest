#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.length();
	int ans[10]={0};
	for(int i=0;i<len;i++)
	{
		ans[s[i]-'0']++;
	}
	for(int i=0;i<10;i++)
	{
		if(ans[i]!=0)
			cout<<i<<":"<<ans[i]<<endl;
	}
	return 0;
}