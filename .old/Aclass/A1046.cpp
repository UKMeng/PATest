#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
int dis[N],A[N];
int main()
{
	int query,n,sum=0;
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		cin>>A[i];
		sum+=A[i];
		dis[i]=sum;
	}
	int a,b;
	cin>>query;
	for(int i=0;i<query;i++)
	{
		cin>>a>>b;
		if(a>b) swap(a,b);
		int temp = dis[b-1]-dis[a-1];
		cout<<min(temp,sum-temp)<<endl;
	}
	return 0;
}