#include <iostream> // 并查集
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, kid[10], esnum, area;
} data[1010];
struct node {
    int id, pnum;
    double avg_num, avg_area;
    bool flag = false;
} ans[10010];
int father[10010];
bool visit[10010];
int find(int x) {
    while(x != father[x]) x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB) father[faA] = faB;
    else father[faB] = faA;
}
bool cmp(node a, node b) {
    if(a.avg_area != b.avg_area) return a.avg_area > b.avg_area;
    else return a.id < b.id;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < 10000; i++) father[i] = i;
    for(int i = 0; i < n; i++) {
        int knum;
        cin >> data[i].id >> data[i].fid >> data[i].mid >> knum;
        for(int j = 0; j < knum; j++) {
            cin >> data[i].kid[j];
            visit[data[i].kid[j]] = true;
            Union(data[i].kid[j], data[i].id);
        }
        cin >> data[i].esnum >> data[i].area;
        visit[data[i].id] = true;
        if(data[i].fid != -1) {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
    }
    for(int i = 0; i < n; i++) {
        int tid = find(data[i].id);
        ans[tid].id = tid;
        ans[tid].avg_num += data[i].esnum;
        ans[tid].avg_area += data[i].area;
        ans[tid].flag = true;
    }
    int cnt = 0;
    for(int i = 0; i < 10000; i++) {
        if(visit[i]) ans[find(i)].pnum++;
        if(ans[i].flag) cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].avg_num = (double)(ans[i].avg_num * 1.0 / ans[i].pnum);
            ans[i].avg_area = (double)(ans[i].avg_area * 1.0 / ans[i].pnum);
        }
    }
    sort(ans, ans + 10000, cmp);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].pnum, ans[i].avg_num, ans[i].avg_area);
    }
    return 0;
}  