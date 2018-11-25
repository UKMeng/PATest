#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int status;

struct Stu
{
	char id[7];
	char name[9];
	int score;
}stu[100010];

bool cmp(Stu a, Stu b)
{
	int s2 = strcmp(a.name, b.name);
	int s1 = strcmp(a.id, b.id);
	if (status == 1) return s1 < 0;
	if (status == 2) 
	{
		if (s2 != 0) return s2 < 0;
		else return s1 < 0;
	}
	if (status == 3)
	{
		if (a.score != b.score) return a.score < b.score;
		else return s1 < 0;
	}
}

int main()
{
	int N,M;
	cin >> N >> M;
	status = M;
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].score);  // cin会超时
	}
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++)
		cout << stu[i].id << " " << stu[i].name << " " << stu[i].score << endl; // 291ms, printf 134ms
	return 0;
}