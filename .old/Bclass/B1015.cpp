#include <iostream>
#include <algorithm>
using namespace std;

struct Stu
{
	long long id;
	int de,cai,flag;
}stu[100010];

bool cmp(Stu a, Stu b)
{
	int scorea = a.de + a.cai;
	int scoreb = b.de + b.cai;
	if (a.flag != b.flag) return a.flag < b.flag;
	else if (scorea != scoreb) return scorea > scoreb;
	else if (a.de != b.de) return a.de > b.de;
	else return a.id < b.id;
}	

int main()
{
// input
	int N, L, H;
	scanf ("%d%d%d", &N, &L, &H);
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		scanf ("%lld%d%d", &stu[i].id, &stu[i].de, &stu[i].cai);     // 这里使用scanf都花了275ms，cin会超时
		if (stu[i].de < L || stu[i].cai < L)
			stu[i].flag = 5;
		else if (stu[i].de >= H && stu[i].cai >= H)
		{
			stu[i].flag = 1;
			count++;
		}
		else if (stu[i].de >= H && stu[i].cai < H)
		{
			stu[i].flag = 2;
			count++;
		}
		else if (stu[i].de < H && stu[i].cai < H && stu[i].de >= stu[i].cai)
		{
			stu[i].flag = 3;
			count++;
		}
		else 
		{
			stu[i].flag = 4;
			count++;
		}
	}
// sort
	sort(stu, stu + N, cmp);

// output
	cout << count << endl;
	for (int i = 0; i < count; i++)
		cout << stu[i].id << " " << stu[i].de << " " << stu[i].cai << endl;
	return 0;
}