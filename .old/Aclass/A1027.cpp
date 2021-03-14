#include <iostream>
using namespace std;
int main(){
	char Mars[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	int r,g,b;
	cin>>r>>g>>b;
	cout<<"#";
	cout<<Mars[r/13]<<Mars[r%13];
	cout<<Mars[g/13]<<Mars[g%13];
	cout<<Mars[b/13]<<Mars[b%13];
	return 0;
}