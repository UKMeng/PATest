#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Stu
{
	int id;
	int grade[4];
	int rank[4];
}stu[2010];

int sub;
char cla[4] = {'A','C','M','E'};

bool cmp (Stu x, Stu y)
{
	if (x.grade[sub] != y.grade[sub]) return x.grade[sub] > y.grade[sub];
	else return x.id < y.id;
}

int find (Stu stu[],int n, int id_to_find)
{	
	int i;
	for (i = 0; i < n; i++)
	{
		if (stu[i].id == id_to_find) 
			{
				break;
			}
	}
	if (i == n) return -1;
	else return i;  
}

void Max(Stu stu[], int pos)
{
	int j = 0;
	for (int i = 0;i < 4; i++)
	{
		if (stu[pos].rank[i] < stu[pos].rank[j])
			j = i;
	}
	cout << stu[pos].rank[j] << " " << cla[j] << endl;
}
int main()
{
// input
	int N, M;
	int pos[2010] = {-1};
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = floor((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3.0 + 0.5);
	}
// sort
	for (sub = 0; sub < 4; sub++)
	{
		sort(stu, stu + N, cmp);
		stu[0].rank[sub] = 1;
		for (int i = 1; i < N; i++)
		{
			if(stu[i].grade[sub] == stu[i-1].grade[sub]) stu[i].rank[sub] = stu[i-1].rank[sub];
			else stu[i].rank[sub] = i + 1;
		}
	}
// find
	for (int i = 0; i < M; i++)
	{
		int id_;
		cin >> id_;
		pos[i] = find(stu, N, id_);
	}
	for (int i = 0; i < M; i++)
	{
		if (pos[i] == -1) cout << "N/A" << endl;
		else 
			Max(stu, pos[i]);
	}
	return 0;
}