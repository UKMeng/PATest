#include <iostream>
#include <cstring>
using namespace std;
char numb[110][19];
int main()
{
	int N;
	cin>>N;
	int power[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char test[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int flag=0;
	for(int i=0;i<N;i++)
	{
		cin>>numb[i];
		int ans=0,anon=0;
		for(int j=0;j<17;j++)
		{
			if(numb[i][j]<'0'||numb[i][j]>'9')
			{
				cout<<numb[i]<<endl;
				flag=1;
				anon=1;
				break;
			}
			ans+=(numb[i][j]-'0')*power[j];
		}
		if(anon==1)
			continue;
		if(test[ans%11]!=numb[i][17])
		{
			cout<<numb[i]<<endl;
			flag=1;
		}
	}
	if(flag==0)
		cout<<"All passed"<<endl;
	return 0;
}