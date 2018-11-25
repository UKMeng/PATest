#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Stu
{
	string id;
	int score, lid, rank, lrank;
}stu[30010];

bool cmp(Stu a, Stu b)
{
	if(a.score != b.score) return a.score > b.score;
	else if (a.lid != b.lid) return a.lid < b.lid;
	else return a.id < b.id;
}

int main()
{
	int N;
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> stu[j + num].id >> stu[j + num].score;
			stu[j + num].lid = i + 1;
		}
		sort(stu + num, stu + num + K, cmp);
		stu[num].lrank = 1;
		for (int j = 1; j < K; j++)
		{
			if (stu[num + j].score == stu[num + j -1].score) stu[num + j].lrank = stu[num + j -1].lrank;
			else stu[num + j].lrank = j + 1;
		}
		num += K;
	}
	cout << num << endl;
	sort(stu, stu + num, cmp);
	stu[0].rank = 1;
	cout << stu[0].id << " " << stu[0].rank << " " << stu[0].lid << " " << stu[0].lrank << endl;
	for (int i = 1; i < num; i++)
	{
		if (stu[i].score == stu[i - 1].score) stu[i].rank = stu[i-1].rank;
		else stu[i].rank = i + 1;
		cout << stu[i].id << " " << stu[i].rank << " " << stu[i].lid << " " << stu[i].lrank << endl;
	}

	return 0;
}