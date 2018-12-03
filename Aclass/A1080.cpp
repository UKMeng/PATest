#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
    int id;
    int GE, GI;
    int final_grade;
    int choice[5];
}stu[40010];

struct School
{
    int quota;
    int accept_id[40010];
    int accept_num;
    int last_id;
}sch[110];

bool cmp(node a, node b)
{
    if (a.final_grade != b.final_grade) return a.final_grade > b.final_grade;
    else return a.GE > b.GE;
}

bool cmpid(int a, int b)
{
    return a < b;
}
int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; i++)
    {    
        scanf("%d", &sch[i].quota);
        sch[i].accept_num = 0;
    }
    for(int i = 0; i < N; i++)
    {
        stu[i].id = i;
        scanf("%d %d", &stu[i].GE, &stu[i].GI);
        stu[i].final_grade = (stu[i].GE + stu[i].GI); // 没必要取平均
        for (int j = 0; j < K; j++)
            scanf("%d", &stu[i].choice[j]);
    }
    sort(stu, stu + N, cmp);
    // for (int i = 0; i < N; i++)
    //     cout << stu[i].id << " " << stu[i].GE << " " << stu[i].GI << " " << endl;
    sch[stu[0].choice[0]].accept_id[0] = stu[0].id;
    sch[stu[0].choice[0]].accept_num ++;
    sch[stu[0].choice[0]].last_id = stu[0].id;
    for (int i = 1; i < N; i++)
    {
        if (stu[i].final_grade == stu[i-1].final_grade && stu[i].GE == stu[i-1].GE)
        {
            for (int j = 0; j < K; j++)
            {
                if (sch[stu[i].choice[j]].last_id == stu[i-1].id)
                {
                    sch[stu[i].choice[j]].accept_id[sch[stu[i].choice[j]].accept_num++] = stu[i].id;
                    sch[stu[i].choice[j]].last_id = stu[i].id;
                    break;
                }
                else if (sch[stu[i].choice[j]].accept_num >= sch[stu[i].choice[j]].quota)
                    continue;
                else 
                {
                    sch[stu[i].choice[j]].accept_id[sch[stu[i].choice[j]].accept_num++] = stu[i].id;
                    sch[stu[i].choice[j]].last_id = stu[i].id;
                    break;
                }
            }
        }
        else 
        {
            for(int j = 0; j < K; j++)
            {
                if (sch[stu[i].choice[j]].accept_num >= sch[stu[i].choice[j]].quota)
                        continue;
                else 
                {
                sch[stu[i].choice[j]].accept_id[sch[stu[i].choice[j]].accept_num++] = stu[i].id;
                sch[stu[i].choice[j]].last_id = stu[i].id;
                break;
                }
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        sort(sch[i].accept_id, sch[i].accept_id + sch[i].accept_num, cmpid);
        for (int j = 0; j < sch[i].accept_num; j++)
        {
            if (j != 0) cout << " ";
            cout << sch[i].accept_id[j];
        }
        cout << endl;
    }
    return 0;
}