#include <iostream>
using namespace std;
int main()
{
	int count=0,n;
	cin>>n;
	while(n!=1)
	{
		if(n%2==0)
			n=n/2;
		else n = 3*n-1;
		count++;
	}
	cout<<count;
	return 0;
}