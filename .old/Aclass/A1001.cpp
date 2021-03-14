#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  string c=to_string(a+b);
  if(c[0]=='-')
  {
    cout<<'-';
    c.erase(c.begin(),c.begin()+1);
  }
  int len=c.length();
  for (int i=0;i<len;i++)
  {
    if((len-i)%3==0&&i!=0&&len-i!=0) cout<<',';
    cout<<c[i];
  }
  /*reverse(c.begin(),c.end());
  int num=1;
  for(int i=0;i<len;i++)
  {
    if(i==len-1) break;
    if(c[len+num-2]=='-'&&i==len-2) break;
    if((i+1)%3==0) c.insert(c.begin()+i+(num++),',');
  }
  reverse(c.begin(),c.end());
  cout<<c<<endl;*/
  return 0;
}