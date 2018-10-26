#include <iostream>
using namespace std;
struct people
{
	char name[16];
	int hour1,min1,sec1,hour2,min2,sec2;
}first,last,temp;
bool zao(people a,people b)//如果a比b早，输出1
{
	if(a.hour1!=b.hour1) return a.hour1<b.hour1;
	else if(a.min1!=b.min1) return a.min1<b.min1;
	else return a.sec1<b.sec1;
}
bool wan(people a,people b)//如果a比b晚，输出1
{
	if(a.hour2!=b.hour2) return a.hour2>b.hour2;
	else if(a.min2!=b.min2) return a.min2>b.min2;
	else return a.sec2>b.sec2;
}
void init()
{
	last.hour2=last.min2=last.sec2=0;
	first.hour1=23;
	first.min1=first.sec1=59;
}
int main()
{
	init();
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d",temp.name,&temp.hour1,&temp.min1,&temp.sec1,&temp.hour2,&temp.min2,&temp.sec2);
		if(zao(temp,first))
		{
			first=temp;
		}
		if(wan(temp,last))
		{
			last=temp;
		}
	}
	cout<<first.name<<" "<<last.name<<endl;
	return 0;
}