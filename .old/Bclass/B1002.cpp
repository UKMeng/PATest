#include <iostream>
#include <cstring>
using namespace std;
string num_cn[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
	string s;
	cin>>s;
	int len=s.length(),sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=s[i]-'0';
	}
	if(sum/100)
		cout<<num_cn[sum/100]<<" "<<num_cn[(sum%100)/10]<<" "<<num_cn[sum%10]<<endl;
	else if(sum/10)
		cout<<num_cn[(sum%100)/10]<<" "<<num_cn[sum%10]<<endl;
	else cout<<num_cn[sum%10]<<endl;
	return 0;
}