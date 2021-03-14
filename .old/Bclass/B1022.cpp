#include <iostream>
using namespace std;
int main(){
	int z[40]={0};
	int a,b,d,c;
	cin>>a>>b>>d;
	c=a+b;
	int num=0;
	do{
		z[num++]=c%d;
		c=c/d;
	}while(c);
	for(int i=0;i<num;i++){
		cout<<z[num-i-1];
	}
	return 0;
}