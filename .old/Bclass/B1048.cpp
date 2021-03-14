#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char oddchar[13]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int main()
{
	string s1,s2;string ans;
	//char ans[110]={0};
	cin>>s1>>s2;
	int len1=s1.length(),len2=s2.length();
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(int i=0;i<max(len1,len2);i++)
	{
		int numA=i<len1?s1[i]-'0':0;
		int numB=i<len2?s2[i]-'0':0;
		if (i%2==0)
		{
			//ans[i]=oddchar[(numA+numB)%13];
			ans.append(1,oddchar[(numA+numB)%13]);
		}
		else 
		{
			int temp=numB-numA;
			if(temp<0) temp+=10;
			//ans[i]=temp+'0';
			ans.append(1,temp+'0');
		}
	}
	//int len=ans.length();对string类型的逐一赋值貌似会出现一些问题，比如元素赋进去了但是长度依然为0
	//cout<<len;
	//cout<<ans.end()-ans.begin();
	reverse(ans.begin(),ans.end());
	cout<<ans;
	//for(int i=max(len1,len2)-1;i>=0;i--)
	//{
	//	cout<<ans[i];
	//}
	//
	//cout<<ans<<endl;
	return 0;
}