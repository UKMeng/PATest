#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 210;
const int INF = 0x3fffffff;
int n, m, ha[maxn], G[maxn][maxn], d[maxn], MAXha = -1, numPath = 0;
double MAXav = -1.0;
map<string, int> cityid;
map<int, string> cityname;
vector<int> pre[maxn], tempPath, ans;
bool vis[maxn];
void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
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
                if(G[u][v] + d[u] < d[v]) {
                    d[v] = G[u][v] + d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(G[u][v] + d[u] == d[v]) pre[v].push_back(u);
            }
        }
    }
}
void DFS(int v) {
    if(v == 0) {
        numPath++;
        tempPath.push_back(v);
        int th = 0;
        double tav;
        for(int i = tempPath.size() - 1; i >= 0; i--) th += ha[tempPath[i]];
        tav = th * 1.0 / (tempPath.size() - 1);
        if(th > MAXha) {
            ans = tempPath;
            MAXha = th;
            MAXav = tav;
        } else if(th == MAXha) {
            if(MAXav < tav) {
                ans = tempPath;
                MAXav = tav;
            }
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) DFS(pre[v][i]);
    tempPath.pop_back();
}
int main() {
    string start;
    cin >> n >> m >> start;
    cityid[start] = 0;
    cityname[0] = start;
    ha[0] = 0;
    for(int i = 1; i < n; i++) {
        string tn;
        int th;
        cin >> tn >> th;
        cityid[tn] = i;
        cityname[i] = tn;
        ha[i] = th;
    }
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++) {
        string n1, n2;
        int dis, id1, id2;
        cin >> n1 >> n2 >> dis;
        id1 = cityid[n1];
        id2 = cityid[n2];
        G[id1][id2] = dis;
        G[id2][id1] = dis;
    }
    Dijkstra(0);
    DFS(cityid["ROM"]);
    cout << numPath << " " << d[cityid["ROM"]] << " " << MAXha << " " << (int)MAXav << endl;
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << cityname[ans[i]];
        if(i > 0) cout << "->";
    }
    return 0;
}