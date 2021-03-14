#include <iostream>
using namespace std;
const int N=54;
int main()
{
	int deck[N+1]={0},rule[N+1]={0};
	int K;
	cin>>K;
	for(int i=1;i<N+1;i++)
	{
		deck[i]=i;
		cin>>rule[i];
	}
	for(int i=0;i<K;i++)
	{	
		int temp[N+1]={0};
		for(int i=1;i<N+1;i++)
		{
			temp[rule[i]]=deck[i];
		}
		for(int i=1;i<N+1;i++)
		{
			deck[i]=temp[i];
		}
	}
	char cmp[5]={'S','H','C','D','J'};
	if(deck[1]%13==0)
	{
		cout<<cmp[(deck[1]/13)-1]<<13;
	}else cout<<cmp[(deck[1]/13)]<<deck[1]%13;
	for(int i=2;i<N+1;i++)
	{
		if(deck[i]%13==0)
		{
			cout<<" "<<cmp[(deck[i]/13)-1]<<13;
		}
		else cout<<" "<<cmp[(deck[i]/13)]<<deck[i]%13;
	}
	return 0;
}