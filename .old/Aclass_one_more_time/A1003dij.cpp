#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7fffffff;
const int maxn = 510;
int G[maxn][maxn], weight[maxn], n, m, c1, c2, dis[maxn], num[maxn], w[maxn];
bool vis[maxn];

void dijkstra(int s){
    fill(dis, dis + maxn, INF);
    num[s] = 1;
    dis[s] = 0;
    w[s] = weight[s];
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && dis[j] < MIN){
                MIN = dis[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[v][u] != INF){
                if(dis[v] > dis[u] + G[u][v]){
                    dis[v] = dis[u] + G[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if(dis[v] == G[u][v] + dis[u]){
                    if(w[v] < w[u] + weight[v]) w[v] = w[u] + weight[v];
                    num[v] += num[u];
                }
            }
        }
    }
}
int main(){
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
}