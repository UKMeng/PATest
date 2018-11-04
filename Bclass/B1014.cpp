#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	char capt;
	bool flag1=false,flag2=false;
	int len1=s1.length(),len2=s2.length();
	for(int i=0;i<min(len1,len2);i++)
	{
		if(s1[i]==s2[i])
		{
			if(!flag1&&(s1[i]<='G'&&s1[i]>='A'))
			{
				capt=s1[i];
				flag1=true;
				cout<<week[capt-'A']<<" ";
				continue;
			}
			if(flag1)
			{
				if(s1[i]<='9'&&s1[i]>='0')
				{
					cout<<"0"<<s1[i]-'0'<<":";
					flag2=true;
					break;
				}
				else if(s1[i]>='A'&&s1[i]<='N')
				{
					cout<<s1[i]-'A'+10<<":";
					flag2=true;
					break;
				}
				
			}
		}
	}
	int len3=s3.length(),count=0;
	for(int i=0;i<len3;i++)
	{
		if((s3[i]<='z'&&s3[i]>='a')||(s3[i]>='A'&&s3[i]<='Z'))
		{	
			if(s3[i]==s4[i])
			{
				count=i;
				break;
			}	
		}
	}
	if(count<10)
		cout<<"0"<<count<<endl;
	else cout<<count<<endl;
	return 0;
}