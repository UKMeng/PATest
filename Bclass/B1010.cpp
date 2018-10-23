#include <iostream>
using namespace std;
int main()
{
	int co[1010]={0};
	int e,num;
	while(scanf("%d %d ",&num,&e)!=EOF)
	{
		if (e!=0)
			co[e-1]=num*e;
	}
	int flag=1;
	for(int i=1000;i>=0;i--)
	{
		if(co[i]!=0)
		{
			if(flag==1)
			{
				cout<<co[i]<<" "<<i;
				flag=flag-1;
			}
			else 
			{
				cout<<" "<<co[i]<<" "<<i;
			}
		}
	}
	if(flag==1)
		cout<<"0 0"<<endl;
	return 0;
}