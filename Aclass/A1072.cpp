#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1020;
const int INF = 0x3fffffff;
int n, m, k, ds, G[maxn][maxn], d[maxn];
void Dijkstra(int s) {
    bool vis[maxn] = {false};
    fill(d, d + maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n + m; i++) {
        int u = -1, MIN = INF;
        for(int j = 1; j <= n + m; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[v] > G[u][v] + d[u]) d[v] = G[u][v] + d[u];
            }
        }
    }
}
int getid(string a) {
    int t;
    if(a[0] == 'G')  {a.erase(a.begin()); t = n + stoi(a);}
    else t = stoi(a);
    return t;
}
int main() {
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 0; i < k; i++) {
        string a, b;
        int id1, id2, dis;
        cin >> a >> b >> dis;
        id1 = getid(a);
        id2 = getid(b);
        G[id1][id2] = dis;
        G[id2][id1] = dis;
    }
    int soid = -1;
    double minr = -1, MINavg = 999999.9;
    bool f = true, ff = false;
    for(int i = 1; i <= m; i++) {
        Dijkstra(n + i);
        double avg = 0.0, minrt = INF;
        for(int j = 1; j <= n; j++) {
            if(d[j] > ds) {minrt = -1.0; break;}
            if(d[j] < minrt) minrt = 1.0 * d[j];
            // sum += d[j];
            avg += 1.0 * d[j] / n;
        }
        if(minrt == -1.0) continue;
        if(minr < minrt) {
            minr = minrt;
            soid = i;
            MINavg = avg;
        } else if(minr == minrt && MINavg > avg) {
            soid = i;
            MINavg = avg;
        }
    }
    if(soid == -1) cout << "No Solution";
    else {
        printf("G%d\n", soid);
        printf("%.1f %.1f", minr, MINavg);
    }
    return 0;
}