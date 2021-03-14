#include <iostream>
using namespace std;
const int C = 100;
int main()
{
	long long c1,c2,time;
	int hour,min,sec;
	cin>>c1>>c2;
	int ans = c2-c1;
	if(ans%100 >=50)
		time = ans/C +1;
	else time = ans/C;
	hour=time/3600;
	time = time%3600;
	min = time/60;
	sec = time%60;
	printf("%02d:%02d:%02d",hour,min,sec);
	return 0;
}