#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 0x7fffffff;
struct node {
    int comeT, serT;
} newcos;
int convertTime(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}
vector<node> cost;
bool cmp(node a, node b) {return a.comeT < b.comeT;}
int endTime[110];
int main() {
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    int stTime = convertTime(8, 0, 0);
    int edTime = convertTime(17, 0, 0);
    for(int i = 0; i < k; i++) endTime[i] = stTime;
    for(int i = 0; i < n; i++) {
        int th, tm, ts, sert, comt;
        scanf("%d:%d:%d %d", &th, &tm, &ts, &sert);
        comt = convertTime(th, tm, ts);
        sert = convertTime(0, sert, 0);
        if(comt > edTime) continue;
        newcos.comeT = comt;
        newcos.serT = sert;
        cost.push_back(newcos);
    }
    sort(cost.begin(), cost.end(), cmp);
    for(int i = 0; i < cost.size(); i++) {
        int wid = -1, minwat = INF;
        for(int j = 0; j < k; j++) {
            if(endTime[j] < minwat) {
                minwat = endTime[j];
                wid = j;
            }
        }
        if(minwat <= cost[i].comeT) endTime[wid] = cost[i].comeT + cost[i].serT;
        else {
            endTime[wid] = minwat + cost[i].serT;
            ans += minwat - cost[i].comeT;
        }
    }
    printf("%.1f", (double)(1.0 * ans / 60.0 / cost.size()));
    return 0;
}