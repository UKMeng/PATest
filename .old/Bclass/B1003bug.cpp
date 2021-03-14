#include <iostream> // bug
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	getchar();
	string s;
	bool ans[10];
	for(int i = 0; i < N; i++)
	{
		getline(cin, s);
		int len = s.length();
		bool flag1 = false, flag2 = false, flag3 = false;
		int num1 = 0, num2 = 0, num3 = 0;
		int j;
		for(j = 0; j < len; j++)
		{
			// if(s[j] != 'P' || s[j] != 'A' || s[j] != 'T')	break;
			// cout << "1";
			if(!flag1)
			{
				if(s[j] == 'A') {num1++; continue;}
				else if(s[j] == 'P') {flag1 = true; continue;}
				else break;
			}
			else if(flag1 && !flag2)
			{
				if(s[j] == 'A') {flag2 = true; continue;}
				else break;
			}
			else if(flag1 && flag2 && !flag3)
			{
				if(s[j] == 'A') {num2++; continue;}
				else if(s[j] == 'T') {flag3 = true; continue;}
				else break;
			}
			else if(flag1 && flag2 && flag3)
			{
				if(s[j] == 'A') {num3++; continue;}
				else if(s[j] != 'A') break;
			}
			else break;
		}
		// cout << num2;
		// cout << j;
		if(j == len && len > 0)
		{
			if(num3 == num1 * (num2 + 1)) ans[i] = true;
			else ans[i] = false;
		}
		else ans[i] = false;
	}
	for(int i = 0; i < N; i++)
	{
		if(ans[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}