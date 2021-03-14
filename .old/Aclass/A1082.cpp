#include <iostream>
#include <cstring>
using namespace std;
char chnum[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char danwei[5][5]={"Shi","Bai","Qian","Wan","Yi"};
int main()
{
	string num;
	cin>>num;
	int len = num.length();
	int left = 0, right = len-1;
	if (num[0] == '-')
	{
		cout << "Fu";
		left++;
	}
	while (left + 4 <= right)
		right -= 4;
	while (left < len)
	{
		bool flag = false;
		bool isPrint = false;
		while (left <= right)
		{
			if (left > 0 && num[left] == '0')   // 考虑输入是0的情况
				flag = true;
			else 
			{
				if (flag == true)
				{
					cout << " ling";
					flag = false;
				}
				if (left > 0) cout << " ";
				cout << chnum[num[left]-'0'];
				isPrint = true;
				if (left != right)
					cout << " " << danwei[right-left-1];
			}
			left++;
		}
		if(isPrint == true && right != len-1 )
		{
			cout << " " << danwei[(len-1-right)/4 + 2];
		}
		right += 4;
	}
	return 0;
}
/*void Ge(char gew, bool flag)
{
	if (gew - '0' != 0)
	{
		if (flag == true)
		{
			cout << " " << chnum[gew-'0'];
		}
		if (flag == false)
		{
			cout << " ling" << " " << chnum[gew-'0'];
		}
	}
}
void Shi(char shiw, char gew, bool flag)
{
	if (shiw - '0' != 0)
	{
		if (flag == true)
		{
			cout << " " << chnum[shiw-'0'] << " Shi";
			Ge(gew, flag);
		}
		else
		{
			cout << " ling" << " " << chnum[shiw-'0'] << " Shi";
			flag = true;
			Ge(gew, flag);
		}
	}
	else
	{
		flag = false;
		Ge(gew, flag);
	}
}
void Bai(char baiw, char shiw, char gew, bool flag)
{
	if (baiw - '0' != 0)
	{
		if (flag == true)
		{
			cout << " " << chnum[baiw-'0'] << " Bai";
			Shi(shiw, gew, flag);
		}
		else 
		{
			cout << " ling" << " " << chnum[baiw-'0'] << " Bai";
			flag = true;
			Shi(shiw, gew, flag);
		}
	}
	else 
	{
		flag = false;
		Shi(shiw, gew, flag);
	}
}
void Qian(char qianw, char baiw, char shiw, char gew, bool flag)
{
	if (qianw - '0' != 0)
	{
		if (flag == true)
		{
		 	cout << chnum[qianw-'0'] << " Qian";
			Bai(baiw, shiw, gew, flag);
		}
		else
		{
			cout << " "<< chnum[qianw-'0'] << " Qian";
			flag = true;
			Bai(baiw, shiw, gew, flag);

		}
	}
	else
	{
		flag = false;
		Bai(baiw, shiw, gew, flag);
	}
}
int main()
{
	string num;
	cin>>num;
	if (num[0]=='-') 
	{
		cout << "Fu ";
		num.erase(0,1);
	}
	int len = num.length();
	if (len == 9)
	{
		bool flag1 = false;
		cout << chnum[num[0]-'0'] << " Yi";
		Qian(num[1],num[2],num[3],num[4],flag1);
		if (num[1] == '0' && num[2] == '0' && num[3] == '0' && num[4] == '0') 
		{}
		else cout << " Wan";
		Qian(num[5],num[6],num[7],num[8],flag1);
	}
	else if (len == 8)
	{
		bool flag1 = true;
		Qian(num[1],num[2],num[3],num[4],flag1);
		cout << " Wan";
		flag1 = false;
		Qian(num[5],num[6],num[7],num[8],flag1);
	}
	else if (len == 7)
	{
		bool flag1 
	}
	return 0;
}*/