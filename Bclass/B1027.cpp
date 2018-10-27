#include <iostream>
using namespace std;
const int N=1010;
void print(int a,int n,char c)
{
	for(int i=0;i<(n-a);i++)
		cout<<" ";
	for(int i=0;i<a*2-1;i++)
		cout<<c;
	cout<<endl;
}
int main()
{
	int num,res,count;
	int layer[N];
	char c;
	layer[0]=1;
	for(int i=1;i<N;i++)
		layer[i]=layer[i-1]+2*((i+1)*2-1);//存储n层所需的字符数，其实直接可以用数学解法；
	cin>>num>>c;
	count=0;
	while(num>=layer[count])
		count++;
	res=num-layer[count-1];
	for(int i=count;i>0;i--)
	{
		print(i,count,c);
	}
	for(int i=2;i<count+1;i++)
	{
		print(i,count,c);
	}
	cout<<res<<endl;
	return 0;
}