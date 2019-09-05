// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int INF = 1000000000;
// const int maxn = 510;
// int n, m, c1, c2, G[maxn][maxn], d[maxn], weight[maxn], num[maxn], w[maxn];
// bool vis[maxn];
// void Dijkstra(int s) {
//     fill(d, d + maxn, INF);
//     fill(w, w + maxn, 0);
//     fill(num, num + maxn, 0);
//     d[s] = 0;
//     num[s] = 1;
//     w[s] = weight[s];
//     for(int i = 0; i < n; i++) {
//         int u = -1, MIN = INF;
//         for(int j = 0; j < n; j++) {
//             if(vis[j] == false && d[j] < MIN) {
//                 MIN = d[j];
//                 u = j;
//             }
//         }
//         if(u == -1) return;
//         vis[u] = true;
//         for(int v = 0; v < n; v++) {
//             if(vis[v] == false && G[u][v] != INF) {
//                 if(d[u] + G[u][v] < d[v]) {
//                     d[v] = d[u] + G[u][v];
//                     w[v] = w[u] + weight[v];
//                     num[v] = num[u];
//                 }
//                 else if(d[u] + G[u][v] == d[v]) {
//                     if(w[u] + weight[v] > w[v]) w[v] = w[u] + weight[v];
//                     num[v] += num[u];
//                 }
//             }
//         }
//     }
// }
// int main() {
//     fill(G[0], G[0] + maxn * maxn, INF);
//     scanf("%d %d %d %d", &n, &m, &c1, &c2);
//     for(int i = 0; i < n; i++) scanf("%d", &weight[i]);
//     for(int i = 0; i < m; i++) {
//         int id1, id2, wt;
//         scanf("%d %d %d", &id1, &id2, &wt);
//         G[id1][id2] = wt;
//         G[id2][id1] = wt;
//     }
//     Dijkstra(c1);
//     cout << num[c2] << " " << w[c2];
//     return 0;
// }
#include <iostream> // 最短路径 dijkstra算法
#include <algorithm>
using namespace std;
const int INF = 0x7fffffff;
const int maxn = 510;
int G[maxn][maxn], weight[maxn], n, m, c1, c2, dis[maxn], num[maxn], w[maxn];
bool vis[maxn];
void Dijkstra(int s) {
    fill(dis, dis + maxn, INF);
    num[s] = 1;
    dis[s] = 0;
    w[s] = weight[s];
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && dis[j] < MIN) {
                MIN = dis[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[v][u] != INF) {
                if(dis[v] > dis[u] + G[u][v]) {
                    dis[v] = dis[u] + G[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if(dis[v] == dis[u] + G[u][v]) {
                    if(w[v] < w[u] + weight[v]) w[v] = w[u] + weight[v];
                    num[v] += num[u];
                }
            }
        }
    }
}
int main() {
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++) scanf("%d", &weight[i]);
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++) {
        int g1, g2, power;
        scanf("%d %d %d", &g1, &g2, &power);
        G[g1][g2] = G[g2][g1] = power;
    }
    Dijkstra(c1);
    cout << num[c2] << " " << w[c2];
    return 0;
}