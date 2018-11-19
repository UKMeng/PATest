#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	getchar();//读掉换行符
	string str[110],kuchiguse;
	bool flag=true;
	int minlen=256;
	for (int i=0;i<N;i++)
	{
		getline(cin,str[i]);//读取空格
		reverse(str[i].begin(),str[i].end());
		if(str[i].length()<minlen) minlen=str[i].lengths();
	}
	for (int i=0;i<minlen;i++)
	{
		for(int j=1;j<N;j++)
		{
			if (str[0][i]!=str[j][i])
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
			kuchiguse.append(1,str[0][i]);
			continue;
		}
		else
			break;
	}
	if (kuchiguse.length()==0)
		cout<<"nai"<<endl;
	else 
	{
		reverse(kuchiguse.begin(),kuchiguse.end());
		cout<<kuchiguse<<endl;
	}
	return 0;
}