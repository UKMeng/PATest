#include <iostream>
using namespace std;
int ans[10050];
bool IsPalin(int s[],int num)
{
	for(int i=0;i<(num/2+num%2);i++){
		if(s[i]!=s[num-i]) return false;
	}
	return true;
}
int main(){
	int N,d;
	cin>>N>>d;
	int num=0;
	do{
		ans[num++]=N%d;
		N=N/d;
	}while(N);
	num=num-1;
	if(IsPalin(ans,num))
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(int i=num;i>=0;i--){
		cout<<ans[i];
		if(i!=0)
			cout<<" ";
	}
	return 0;
}