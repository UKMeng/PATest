#include <iostream> // 最短路径 Dijkstra算法 + DFS
#include <algorithm> // 本题不能直用Dijkstra做，因为remain和need在路径上的传递不满足最优子结构（即简单相加），需要在通过DFS遍历一遍所以的最短路径挑选出最佳路径
#include <vector>
using namespace std;
const int maxn = 510;
const int INF = 0x7fffffff;
int cmax, n, sp, m, have[maxn], G[maxn][maxn], d[maxn], need, remain, minNeed = INF, minRemain = INF;
vector<int> pre[maxn], tempPath, path;
bool vis[maxn];
void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n + 1; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n + 1; j++) {
            if(vis[j] == false && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n + 1; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[v] > d[u] + G[u][v]) {
                    pre[v].clear();
                    pre[v].push_back(u);
                    d[v] = d[u] + G[u][v];
                } else if(d[v] == d[u] + G[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void dfs(int index) {
    if(index == 0) {
        tempPath.push_back(index);
        need = 0, remain = 0;
        for(int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if(have[id] > 0) remain += have[id];
            else {
                if(remain >= abs(have[id])) {
                    remain -= abs(have[id]);
                } else {  
                    need += abs(have[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if(need == minNeed && minRemain > remain) {
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
    } else {
        tempPath.push_back(index);
        for(int i = 0; i < pre[index].size(); i++) {
            dfs(pre[index][i]);
        }
        tempPath.pop_back();
    }
}
int main() {
    cin >> cmax >> n >> sp >> m;
    for(int i = 1; i <= n; i++) {
        cin >> have[i];
        have[i] -= cmax / 2;
    }
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++) {
        int t1, t2, len;
        cin >> t1 >> t2 >> len;
        G[t1][t2] = G[t2][t1] = len;
    }   
    Dijkstra(0);
    dfs(sp);
    cout << minNeed << " ";
    for(int i = path.size() - 1; i >= 0; i--) {
        if(i != path.size() - 1) cout << "->";
        cout << path[i];
    }
    cout << " " << minRemain;
    return 0;
}