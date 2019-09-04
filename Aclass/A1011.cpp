// #include <iostream>
// using namespace std;
// int main()
// {
// 	char c[4]={"WTL"};
// 	float temp,max=1.0;
// 	for (int i=0;i<3;i++)
// 	{
// 		float ans = 1;
// 		int maxchar;
// 		for(int j=0;j<3;j++)
// 		{
// 			cin>>temp;
// 			if (temp > ans)
// 				{
// 					ans=temp;
// 					maxchar = j;
// 				}
// 		}
// 		max *= ans;
// 		printf("%c ",c[maxchar]);
// 	}
// 	printf("%.2f",(max*0.65-1)*2);
// 	return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string text = "WTL";
int main() {
	vector<double> ans;
	for(int i = 0; i < 3; i++) {
		double tempmax = 0.0, num;
		int maxid;
		for(int j = 0; j < 3; j++) {
			cin >> num;
			if(num > tempmax) {
				tempmax = num;
				maxid = j;
			}
		}
		cout << text[maxid] << " ";
		ans.push_back(tempmax);
	}
	double a = (ans[0] * ans[1] * ans[2] * 0.65 - 1.0) * 2;
	printf("%.2f", a);
	return 0;
}