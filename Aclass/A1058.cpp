#include <iostream>
using namespace std;
struct money
{
	int gal,si,kn;
}A,B,C;
int main()
{
	scanf("%d.%d.%d %d.%d.%d",&A.gal,&A.si,&A.kn,&B.gal,&B.si,&B.kn);
	C.gal=C.si=C.kn=0;
	if(A.kn+B.kn<29) C.kn=A.kn+B.kn;
	else{
		C.kn=A.kn+B.kn-29;
		C.si+=1;
	}
	if(A.si+B.si+C.si<17) C.si=C.si+A.si+B.si;
	else{
		C.si=A.si+B.si+C.si-17;
		C.gal+=1;
	}
	C.gal=C.gal+B.gal+A.gal;
	cout<<C.gal<<"."<<C.si<<"."<<C.kn;
	return 0;
}