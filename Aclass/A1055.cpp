#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Richs
{
	char name[9];
	int age, worth;
}rich[100010];

bool cmp(Richs a, Richs b)
{
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else 
	{
		int s = strcmp(a.name, b.name);
		return s < 0;
	}
}

int main()
{
// input
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d", rich[i].name, &rich[i].age, &rich[i].worth);
	}
// sort
	sort(rich, rich + N, cmp);
// output
	for (int i = 0; i < K; i++)
	{
		cout << "Case #" << i + 1 << ":" << endl;
		int num, min, max;
		scanf("%d %d %d", &num, &min, &max);
		int temp = num;
		for (int j = 0; j < N; j++)
		{
			if (rich[j].age >= min && rich[j].age <= max)
			{
				cout << rich[j].name << " " << rich[j].age << " " << rich[j].worth << endl;
				num--;
			}
			if (num == 0) break;
		}
		if (temp == num) cout << "None" << endl;
	}
	return 0;
}