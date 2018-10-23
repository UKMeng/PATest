#include <cstdio>
const int maxn = 100010;
int main()
{
	int N,id,s;
	scanf("%d",&N);
	int score[maxn]={0};
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&id,&s);
		score[id]+=s;
	}
	int maxid=0,maxs=0;
	for(int i=1;i<=N;i++)
	{
		if(maxs<score[i])
		{
			maxid = i;
			maxs = score[i];
		}
	}
	printf("%d %d",maxid,maxs);
	return 0;
}