#include <iostream>
using namespace std;
int main()
{
	int N;
	int nans[9]={1,2,3,4,5,6,7,8,9};
	cin>>N;
	for(int i=0;i<N/100;i++)
	{
		cout<<'B';
	}
	for(int i=0;i<(N%100)/10;i++)
	{
		cout<<'S';
	}
	for(int i=0;i<N%10;i++)
		cout<<nans[i];
	return 0;
}
