#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
    int weight, rank, id, index;
}mouse[1010];
bool cmp1(node a, node b) {return a.id < b.id;}
bool cmp2(node a, node b) {return a.index < b.index;}
int main() {
    int np, ng, group, t, n;
    queue<node> cm;
    cin >> np >> ng;
    for(int i = 0; i < np; i++) {cin >> mouse[i].weight; mouse[i].index = i;}
    for(int i = 0; i < np; i++) {cin >> n; mouse[n].id = i;}
    sort(mouse, mouse + np, cmp1);
    for(int i = 0; i < np; i++) cm.push(mouse[i]);
    t = np;
    while(1) {
        int size = cm.size(), cnt = 0;
        if(size == 1) {
            node temp = cm.front();
            mouse[temp.id].rank = 1;
            break;
        }
        group = t / ng;
        if(t % ng != 0) group++;
        t = group;
        for(int i = 0; i < group; i++) {
            node fatm;
            fatm.weight = -1;   
            for(int j = 0; j < ng; j++) {
                if(cnt == size) break;
                node temp = cm.front();
                // cout << mouse[temp.id].weight << " ";
                cm.pop();
                mouse[temp.id].rank = group + 1;
                if(temp.weight > fatm.weight) fatm = temp;
                // cout << fatm.weight << " ";
                cnt++;
            }
            // cout << endl;
            // cout << mouse[fatm.id].weight << " " ;
            cm.push(fatm);
        }
    }
    sort(mouse, mouse + np, cmp2);
    for(int i = 0; i < np; i++) {if(i != 0) cout << " "; cout << mouse[i].rank;}
    return 0;
}