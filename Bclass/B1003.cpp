#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	string s1="abcdefg";
	reverse(s1.begin(),s1.end());
	cout<<s1<<endl;
	return 0;
}