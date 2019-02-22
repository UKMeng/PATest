#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int maxn = 510;
int n, m, s, z, G[maxn][maxn], d[maxn], cost[maxn][maxn], c[maxn], pre[maxn];
bool vis[maxn];
void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    fill(c, c + maxn, INF);
    fill(pre, pre + maxn, -1);
    d[s] = 0;
    c[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v] = u;
                    c[v] = c[u] + cost[u][v];
                } else if(d[u] + G[u][v] == d[v]) {
                    if(c[v] > c[u] + cost[u][v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
void dfs(int z) {
    if(pre[z] != -1) dfs(pre[z]);
    cout << z << " ";
}
int main() {
    cin >> n >> m >> s >> z;
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(cost[0], cost[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++) {
        int id1, id2, dis, ct;
        cin >> id1 >> id2 >> dis >> ct;
        G[id1][id2] = dis;
        G[id2][id1] = dis;
        cost[id1][id2] = ct;
        cost[id2][id1] = ct;
    }
    Dijkstra(s);
    dfs(z);
    cout << d[z] << " " << c[z] << endl;
    return 0;
}