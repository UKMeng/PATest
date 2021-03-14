#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int G[1010][1010];

vector<int> dijkstra(int start){
    vector<bool> visit(n+1);
    vector<int> dis(n+1, 0x3f3f3f3f);
    dis[start] = 0;
    for(int i = 1; i <= n; i++){
        int MIN_DIS = 0x3f3f3f3f;
        int u = -1;
        for(int j = 1; j <= n; j++){
            if(!visit[j] && dis[j] < MIN_DIS){
                MIN_DIS = dis[j];
                u = j;
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n; v++){
            if(!visit[v] && G[u][v] > 0){
                if(dis[v] > dis[u] + G[u][v]) {
                    dis[v] = dis[u] + G[u][v];
                }
            }
        }
    }
    return dis;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        G[u][v] = t;
        G[v][u] = t;
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        vector<int> q(n);
        for(int j = 0; j < n; j++){
            scanf("%d", &q[j]);
        }
        vector<int> dis = dijkstra(q[0]);
        bool flag = true;
        for(int j = 1; j < n; j++){
            if(dis[q[j]] < dis[q[j-1]]){
                flag = false;
                break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}