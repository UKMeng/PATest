#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;
const int INF = 0x7fffffff;
vector<int> check;
int n, G[maxn][maxn];
bool dijkstra(int s) {
    int d[maxn];
    fill(d, d + maxn, INF);
    vector<bool> vis(maxn, false);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 1; j <= n; j++) {
            if(vis[j] == false && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if(d[check[i]] == MIN) u = check[i]; 
        else return false;
        vis[u] = true;
        for(int v = 0; v < n + 1; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[v] > d[u] + G[u][v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
    return true;
}
int main() {
    int ne, k;
    cin >> n >> ne;
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 0; i < ne; i++) {
        int v1, v2, p;
        cin >> v1 >> v2 >> p;
        G[v1][v2] = G[v2][v1] = p;
    }
    cin >> k;
    check.resize(n);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> check[j];
        }
        if(dijkstra(check[0])) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    }
    return 0;
}