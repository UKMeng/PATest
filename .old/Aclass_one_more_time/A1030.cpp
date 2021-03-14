#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x7fffffff;
const int maxn = 510;
int n, m, s, distination, G[maxn][maxn], cost[maxn][maxn], d[maxn], costSum[maxn], pre[maxn];
bool vis[maxn];
void dijkstra(int s){
    fill(d, d + maxn, INF);
    fill(costSum, costSum, INF);
    fill(pre, pre + maxn, -1);
    d[s] = 0;
    costSum[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && MIN > d[j]){
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v ++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[v] > G[u][v] + d[u]){
                    costSum[v] = costSum[u] + cost[u][v];
                    d[v] = d[u] + G[u][v];
                    pre[v] = u;
                } else if(d[v] == d[u] + G[u][v]){
                    if(costSum[v] > costSum[u] + cost[u][v]){
                        costSum[v] = costSum[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
void dfs(int d){
    if(d != s){
        dfs(pre[d]);
    }
    cout << d << " ";
}
int main(){
    cin >> n >> m >> s >> distination;
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(cost[0], cost[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++){
        int t1, t2, dis, cos;
        cin >> t1 >> t2 >> dis >> cos;
        G[t1][t2] = G[t2][t1] = dis;
        cost[t1][t2] = cost[t2][t1] = cos;
    }
    dijkstra(s);
    dfs(distination);
    cout << d[distination] << " " << costSum[distination] << endl;
    return 0;
}