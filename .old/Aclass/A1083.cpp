#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
	char name[11];
	char id[11];
	int score;
}stu[100010];

bool cmp(node a, node b)
{
	return a.score > b.score;
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);
	}
	int max = 0, min = 0;
	bool show = false;
	scanf("%d %d", &min, &max);
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++)
	{
		if (stu[i].score > max)
			continue;
		if (stu[i].score < min)
			break;
		printf("%s %s\n", stu[i].name, stu[i].id);
		show = true;
	}
	if (show == false)
		printf("NONE");
	return 0;
}