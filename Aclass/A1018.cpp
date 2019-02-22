#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 510;
const int INF = 0x3FFFFFFF;
int pa, n, sp, m, ca[maxn], G[maxn][maxn], d[maxn], minNeed = INF, minRemain = INF;
bool vis[maxn];
vector<int> pre[maxn], tempPath, ans;
void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n + 1; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n + 1; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n + 1; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + G[u][v] == d[v]) pre[v].push_back(u);
            }
        }
    }
}
void dfs(int v) {
    if(v == 0) {    
        tempPath.push_back(v);
        int need = 0, remain = 0;
        for(int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if(ca[id] > 0) remain += ca[id];
            else {
                if(remain > abs(ca[id])) remain -= abs(ca[id]);
                else {
                    need += abs(ca[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minRemain = remain;
            ans = tempPath;
        } else if(need == minNeed && remain < minRemain) {
            minRemain = remain;
            ans = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
    tempPath.pop_back();
}
int main() {
    cin >> pa >> n >> sp >> m;
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 1; i <= n; i++) {
        cin >> ca[i];
        ca[i] = ca[i] - pa / 2;
    }
    for(int i = 0; i < m; i++) {
        int id1, id2, dis;
        cin >> id1 >> id2 >> dis;
        G[id1][id2] = dis;
        G[id2][id1] = dis;
    }
    Dijkstra(0);
    dfs(sp);
    cout << minNeed << " ";
    for(int i = ans.size() - 1; i >= 0; i--) {
        if(i != ans.size() - 1) cout << "->";
        cout << ans[i];
    }
    cout << " " << minRemain;
    return 0;
}