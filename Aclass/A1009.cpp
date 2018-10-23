#include <iostream>
using namespace std;
struct Poly
{
	int ex;
	double co;
}poly[1001];
const int MAXN = 2001;
int main()
{
	double ans[MAXN]={0};
	int n,m,e;
	double co;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>poly[i].ex>>poly[i].co;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>e>>co;
		for(int j=0;j<n;j++)
		{
			ans[e+poly[j].ex]+=co*poly[j].co;
		}
	}
	int count=0;
	for(int i=0;i<2001;i++)
	{
		if(ans[i]!=0.0) count++;
	}
	cout<<count;
	for(int i=2000;i>=0;i--)
	{
		if(ans[i]!=0.0)
			printf(" %d %.1f",i,ans[i]);
	}
	return 0;
}
