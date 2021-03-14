#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Stu
{
	int score[5];
	int id;
	int tot_score;
	bool flag;
	int spn; //the number of perfectly solved qusitions.
	int rank;
}stu[10010];

int fullscore[5] = {0};
int N, K, M;
bool cmp(Stu a, Stu b)
{
	if (a.tot_score != b.tot_score) return a.tot_score > b.tot_score;
	else if (a.spn != b.spn) return a.spn > b.spn;
	else if (a.flag != b.flag) return a.flag > b.flag;
	else return a.id < b.id;
}

void showid(int n)   // %05d
{
	if(n<10) cout << "0000" << n << " ";
	else if(n<100) cout << "000" << n << " ";
	else if(n<1000) cout << "00" << n << " ";
	else if(n<10000) cout << "0" << n << " ";
	else cout << n << " ";
}

void showscore(Stu a)
{
	for (int i = 0; i < K; i ++)
	{
		if (a.score[i] == -2) cout << " -";
		else cout << " " << a.score[i];
	}
}

int main()
{
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < K; i++)
		scanf("%d", &fullscore[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
			stu[i].score[j] = -2;
		stu[i].tot_score = 0;
		stu[i].flag = false;
		stu[i].spn = 0;
	}
	for (int i = 0; i < M; i++)
	{
		int tempid = 0, tempqid = 0, temps = 0;
		scanf("%d %d %d", &tempid, &tempqid, &temps);
		stu[tempid-1].id = tempid ;
		if(stu[tempid-1].score[tempqid-1] < temps && temps != -1) 
			{
				stu[tempid-1].score[tempqid-1] = temps;
				stu[tempid-1].flag = true;
			}
		else if (stu[tempid-1].score[tempqid-1] < temps && temps == -1) stu[tempid-1].score[tempqid-1] = 0;
	}
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if(stu[i].score[j] != -2) 
			{
				stu[i].tot_score += stu[i].score[j];
				if (stu[i].score[j] == fullscore[j])
					stu[i].spn ++;
			}
		}
	}
	sort(stu, stu + N, cmp);
	if(stu[0].flag == true)
	{	
		stu[0].rank = 1;
		cout << stu[0].rank << " ";
		showid(stu[0].id);
		cout << stu[0].tot_score;
		showscore(stu[0]);
	}
	for (int i = 1; i < N; i++)
	{
		if (stu[i].flag == true) cout << endl;
		else break;
		if (stu[i].tot_score == stu[i-1].tot_score) stu[i].rank = stu[i-1].rank;
		else stu[i].rank = i + 1;
		cout << stu[i].rank << " ";
		showid(stu[i].id);
		cout << stu[i].tot_score;
		showscore(stu[i]);
	}
	return 0;
}