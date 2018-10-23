#include <iostream>
using namespace std;
int main()
{
	char c[4]={"WTL"};
	float temp,max=1.0;
	for (int i=0;i<3;i++)
	{
		float ans = 1;
		int maxchar;
		for(int j=0;j<3;j++)
		{
			cin>>temp;
			if (temp > ans)
				{
					ans=temp;
					maxchar = j;
				}
		}
		max *= ans;
		printf("%c ",c[maxchar]);
	}
	printf("%.2f",(max*0.65-1)*2);
	return 0;
}