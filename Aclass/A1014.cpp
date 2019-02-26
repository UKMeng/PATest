#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int convert(int hh, int mm) {return hh * 60 + mm;}
struct node{
    int endtime, poptime;
    queue<int> q;
}window[20];
int ans[1010], pt[2010];
int main() {
    int n, m, k, q, id = 0;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 0; i < k; i++) scanf("%d", &pt[i]);
    for(int i = 0; i < n; i++) window[i].endtime = window[i].poptime = convert(8, 0);
    for(int i = 0; i < min(n * m, k); i++) {
        window[id % n].q.push(id);
        window[id % n].endtime += pt[id];
        if(id < n) window[id].poptime = pt[id];
        ans[id] = window[id % n].endtime;
        id++;
    }
    while(id < k) {
        int idx = -1, minPoptime = 0x7fffffff;
        for(int i = 0; i < n; i++) {
            if(window[i].poptime < minPoptime) {
                idx = i;
                minPoptime = window[i].poptime;
            }
        }
        window[idx].q.pop();
        window[idx].q.push(id);
        window[idx].endtime += pt[id];
        window[idx].poptime += pt[window[idx].q.front()];
        ans[id] = window[idx].endtime;
        id++;
    }
    for(int i = 0; i < q; i++) {
        int tid;
        scanf("%d", &tid);
        if(ans[tid - 1] - pt[tid - 1] >= convert(17, 0)) printf("Sorry\n");
        else printf("%02d:%02d\n", ans[tid - 1] / 60, ans[tid - 1] % 60);
    }
    return 0;
}