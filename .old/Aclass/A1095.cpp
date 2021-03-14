#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
struct node {
    int time, status;
    char plate[10];
} newcar[10010];
int convert(int hh, int mm, int ss) {return hh * 3600 + mm * 60 + ss;}
vector<node> ans;
vector<string> maxPlate;
map<string, int> m;
bool cmp1(node a, node b) {
    if(strcmp(a.plate, b.plate) != 0) return strcmp(a.plate, b.plate) < 0;
    else return a.time < b.time;
}
bool cmp2(node a, node b) {return a.time < b.time;}
int main() {
    int n, k, maxTime = -1;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        char status[5];
        int th, tm, ts;
        scanf("%s %d:%d:%d %s", newcar[i].plate, &th, &tm, &ts, status);
        int ttime = convert(th, tm, ts);
        newcar[i].time = ttime;
        if(status[0] == 'i') newcar[i].status = 0;
        else newcar[i].status = 1;
    }
    sort(newcar, newcar + n, cmp1);
    for(int i = 0; i < n - 1; i++) {
        if(strcmp(newcar[i].plate, newcar[i + 1].plate) == 0 && newcar[i].status == 0 && newcar[i + 1].status == 1) {
            ans.push_back(newcar[i]);
            ans.push_back(newcar[i + 1]);
            int tempT = newcar[i + 1].time - newcar[i].time;
            if(m.find(newcar[i].plate) == m.end()) m[newcar[i].plate] = 0;
            m[newcar[i].plate] += tempT;
            if(m[newcar[i].plate] > maxTime) {
                maxPlate.clear();
                maxTime = m[newcar[i].plate];
                maxPlate.push_back(newcar[i].plate);
            } else if(m[newcar[i].plate] == maxTime) maxPlate.push_back(newcar[i].plate);
        }
    }
    sort(ans.begin(), ans.end(), cmp2);
    int now = 0, total = 0;
    for(int i = 0; i < k; i++) {
        int th, tm, ts, temp;
        scanf("%d:%d:%d", &th, &tm, &ts);
        temp = convert(th, tm, ts);
        while(now < ans.size() && ans[now].time <= temp) {
            if(ans[now].status == 0) total++;
            else total--;
            now++;
        }
        printf("%d\n", total);
    }
    for(int i = 0; i < maxPlate.size(); i++) printf("%s ", maxPlate[i].c_str());
    printf("%02d:%02d:%02d", maxTime / 3600, (maxTime % 3600) / 60, maxTime % 60);
    return 0;
}