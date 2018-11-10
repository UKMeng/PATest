#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int N;
	cin>>N;
	string team[1010],pw[1010];
	bool flag[1010]={false};
	int num=0;
	for (int i=0;i<N;i++)
	{
		cin>>team[i]>>pw[i];
		int len=pw[i].length();
		for(int j=0;j<len;j++)
		{
			if(pw[i][j]=='l')
			{
				pw[i][j]='L';
				flag[i]=true;
			}
			if(pw[i][j]=='1')
			{
				pw[i][j]='@';
				flag[i]=true;
			}
			if(pw[i][j]=='0')
			{
				pw[i][j]='%';
				flag[i]=true;
			}
			if(pw[i][j]=='O')
			{
				pw[i][j]='o';
				flag[i]=true;
			}
		}
		if(flag[i]==true)
			num++;
	}
	if(num==0)
		if (N==1)
			cout<<"There is "<<N<<" account and no account is modified"<<endl;
		else
			cout<<"There are "<<N<<" accounts and no account is modified"<<endl;//注意单词的复数形式
	else 
	{
		cout<<num<<endl;
		for(int i=0;i<N;i++)
		{
			if(flag[i]==true)
				cout<<team[i]<<" "<<pw[i]<<endl;
		}
	}
	return 0;
}