#include <iostream>
using namespace std;
int main()
{
	double ans[1001]={0};
	int k,n,cnt=0;
	double temp;
	cin>>k;
	while(k--)
	{
		cin>>n>>temp;
		ans[n]+=temp;
	}
	cin>>k;
	while(k--)
	{
		cin>>n>>temp;
		ans[n]+=temp;
	}
	for (int i = 0; i < 1001; i++) {
        if (ans[i] != 0) cnt++;
    }
	printf("%d",cnt);
	for (int i=1000;i>=0;i--)
	{
		if(ans[i]!=0.0)
		{
			printf(" %d %.1f",i,ans[i]);
		}
	}
	return 0;
}
/*{
	double ans[1001]={0};
	int k,n,cnt=0;
	double temp;
	for(int i=0;i<2;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>n>>temp;
			if(ans[n]==0) cnt++;
			ans[n]+=temp;
		}
	}
	printf("%d",cnt);
	for (int i=1000;i>=0;i--)
	{
		if(ans[i]!=0.0)
		{
			printf(" %d %.1f",i,ans[i]);
		}
	}
	return 0;
}*/