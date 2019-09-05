#include <iostream> // Dijkstra算法重复使用
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1020;
const int INF = 0x3fffffff;
int G[maxn][maxn], n, m, k, maxRange, d[maxn];
bool vis[maxn];
int getID(string s) {
    if(s[0] == 'G') return n + stoi(s.substr(1));
    else return stoi(s);
}
void dijkstra(int a) {
    memset(vis, false, sizeof(vis));
    fill(d, d + maxn, INF);
    d[a] = 0;
    for(int i = 0; i < n + m; i++) {
        int u = -1, MIN = INF;
        for(int j = 1; j <= n + m; j++) {
            if(vis[j] == false && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(vis[v] == false && d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}
int main() {
    cin >> n >> m >> k >> maxRange;
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 0; i < k; i++) {
        string t1, t2;
        int a, b, distance;
        cin >> t1 >> t2 >> distance;
        a = getID(t1);
        b = getID(t2);
        G[a][b] = G[b][a] = distance;
    }
    double ansDis = -1, ansAvg = INF;
    int ansID = -1;
    for(int i = n + 1; i <= n + m; i++) {
        dijkstra(i);
        double minDis = INF, avg = 0;
        for(int j = 1; j <= n; j++) {
            if(d[j] > maxRange) {
                minDis = -1;
                break;
            } 
            // cout << i << " " << j << " " << d[j] << endl;
            if(d[j] < minDis) minDis = d[j];
            avg += 1.0 * d[j];
        }
        avg = avg / n;
        if(minDis == -1) continue;
        if(minDis > ansDis) {
            ansDis = minDis;
            ansAvg = avg;
            ansID = i - n;
        } else if(minDis == ansDis && avg < ansAvg) {
            ansAvg = avg;
            ansID = i - n;
        }
    }
    if(ansID == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansID);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }
    return 0;
}