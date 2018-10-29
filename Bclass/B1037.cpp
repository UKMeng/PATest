#include <iostream>
using namespace std;
struct money
{
	int gal,sic,kn;
}P,A;
int main(){
	scanf("%d.%d.%d %d.%d.%d",&P.gal,&P.sic,&P.kn,&A.gal,&A.sic,&A.kn);
	int g,s,k;
	if(A.kn>=P.kn)	k=A.kn-P.kn;
	else{
		k=A.kn+29-P.kn;
		A.sic-=1;
	}
	if(A.sic>=P.sic) s=A.sic-P.sic;
	else{
		s=A.sic+17-P.sic;
		A.gal-=1;
	}
	if(A.gal>=P.gal) g=A.gal-P.gal;
	else{
		g=A.gal-P.gal+1;
		s=-17+s+1;
		s=-s;
		k=-29+k;
		k=-k;
	}
	printf("%d.%d.%d",g,s,k);
	return 0;
}
