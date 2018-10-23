#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  long a,b;
  cin>>a>>b;
  string s = to_string(a+b);
  int len = s.length();
  for (int i = 0; i<len;i++)
  {
  	cout<<s[i];
  	if(s[i]=='-') continue;
  	if((i+1)%3==len%3&&(i+1)!=len) cout<<',';
  }
  return 0;
}