#include <iostream>
using namespace std;
int main()
{
	int N,a1,a2,b1,b2;
	int count1 = 0,count2=0;
	cin >> N;
	for (int i = 0;i<N;i++)
	{
		cin>>a1>>a2>>b1>>b2;
		if(a2==b2)
			continue;
		if(a2==a1+b1)
			count2++;
		if(b2==a1+b1)
			count1++;
	}
	cout<<count1<<" "<<count2<<endl;
	return 0;
}
