#include <iostream>
using namespace std;
int change(char a)
{
	if (a=='B') return 0;
	if (a=='C') return 1;
	if (a=='J') return 2;
}
int main()
{
	int N;
	cin>>N;
	int as[3]={0},bs[3]={0},ah[3]={0},bh[3]={0};
	int ha,hb;
	char ha1,hb1;
	for(int i=0;i<N;i++)
	{
		cin>>ha1>>hb1;
		ha=change(ha1);
		hb=change(hb1);
		if((ha+1)%3==hb)
		{
			as[0]++;
			bs[2]++;
			ah[ha]++;
		}else if(ha==hb)
		{
			as[1]++;
			bs[1]++;
		}else
		{
			as[2]++;
			bs[0]++;
			bh[hb]++;
		}
	}
	cout<<as[0]<<" "<<as[1]<<" "<<as[2]<<endl;
	cout<<bs[0]<<" "<<bs[1]<<" "<<bs[2]<<endl;
	int maxa=0,maxb=0,flaga=0,flagb=0;
	for(int i=0;i<3;i++)
	{
		if(ah[i]>maxa)
		{
			maxa=ah[i];
			flaga=i;
		}
		if(bh[i]>maxb)
		{
			maxb=bh[i];
			flagb=i;
		}
	}
	char map[3]={'B','C','J'};
	cout<<map[flaga]<<" "<<map[flagb]<<endl;
	return 0;
}