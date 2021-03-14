#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int n, block = 0, maxlayer = 0;
vector<int> G[maxn], lb, la;
bool vis[maxn];
void dfs(int v, int layer) {
    bool isl = false;
    vis[v] = true;
    for(int i = 0; i < G[v].size(); i++) {
        if(vis[G[v][i]] == false) {
            dfs(G[v][i], layer + 1);
            isl = true;
        }
    }
    if(!isl) {
        if(layer > maxlayer) {
            la.clear();
            la.push_back(v);
            maxlayer = layer;
        } else if(layer == maxlayer) la.push_back(v);
    }
}
void dfs1(int v, int layer) {
    bool isl = false;
    vis[v] = true;
    for(int i = 0; i < G[v].size(); i++) {
        if(vis[G[v][i]] == false) {
            dfs1(G[v][i], layer + 1);
            isl = true;
        }
    }
    if(!isl) {
        if(layer > maxlayer) {
            lb.clear();
            lb.push_back(v);
            maxlayer = layer;
        } else if(layer == maxlayer) lb.push_back(v);
    }
}
int main() {
    scanf("%d", &n);
    if(n == 1) {printf("1"); return 0;}
    for(int i = 0; i < n - 1; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        G[id1].push_back(id2);
        G[id2].push_back(id1);
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            dfs(i, 0);
            block++;
        }
    }
    if(block > 1) {printf("Error: %d components", block); return 0;}
    memset(vis, false, sizeof(vis));
    dfs1(la[0], 0);
    for(int i = 0; i < la.size(); i++) {
        bool isSame = false;
        for(int j = 0; j < lb.size(); j++) if(la[i] == lb[j]) {isSame = true; break;}
        if(!isSame) lb.push_back(la[i]);
    }
    sort(lb.begin(), lb.end());
    for(int i = 0; i < lb.size(); i++) printf("%d\n", lb[i]);
    return 0;
}