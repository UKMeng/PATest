#include <iostream>
#include <cstring>
using namespace std;
char word[90][90];
int main()
{
	int num=0;
	while(scanf("%s",word[num])!=EOF) num++;//while(scanf("%s",word[num++])!=EOF); num多加了2
	for(int i=num-1;i>=0;i--){
		cout<<word[i];
		if(i>0) cout<<" ";
	}
	return 0;
}