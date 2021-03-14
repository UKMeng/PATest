#include <iostream>
using namespace std;
struct resident
{
	char name[10];
	int yy,mm,dd;
}l,r,youngest,oldest,temp;
bool cmpy(resident a,resident b)
{
	if (a.yy!=b.yy) return a.yy>b.yy;
	else if(a.mm!=b.mm) return a.mm>b.mm;
	else if(a.dd!=b.dd) return a.dd>b.dd;
}
bool cmpo(resident a,resident b)
{
	if (a.yy!=b.yy) return a.yy<b.yy;
	else if(a.mm!=b.mm) return a.mm<b.mm;
	else if(a.dd!=b.dd) return a.dd<b.dd;
}
void init()
{
	l.yy=youngest.yy=1814;
	r.yy=oldest.yy=2014;
	l.mm=oldest.mm=r.mm=youngest.mm=9;
	l.dd=oldest.dd=r.dd=youngest.dd=6;
}
int main()
{
	init();
	int num,count=0;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{	
		scanf("%s %d/%d/%d",temp.name,&temp.yy,&temp.mm,&temp.dd);
		if(cmpy(r,temp)&&cmpo(l,temp))
		{
			count++;
			if(!cmpy(youngest,temp))
			{
				youngest=temp;
			}
			if(!cmpo(oldest,temp))
			{
			  oldest=temp;
			}
		}
	}
	if(count==0)
	  cout<<"0"<<endl;
	else cout<<count<<" "<<oldest.name<<" "<<youngest.name<<endl;
	return 0;
}