#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 510;
const int INF = 0x7fffffff;
int G[maxn][maxn], t[maxn][maxn], n, m, v1, v2, p[maxn], pre1[maxn], pre2[maxn], p2[maxn], num[maxn], num2[maxn];
bool vis[maxn];
void dfs1(int v1) {
    fill(vis, vis + maxn, false);
    fill(p, p + maxn, INF);
    fill(pre1, pre1 + maxn, -1);
    p[v1] = 0;
    for(int j = 0; j < n; j++) {
        int min = INF, v = -1;
        for(int i = 0; i < n; i++) {
            if(min > p[i] && vis[i] == false) {
                v = i;
                min = p[i];
            }
        }
        if(v == -1) return;
        vis[v] = true;
        for(int w = 0; w < n; w++) {
            if(G[v][w] != INF && vis[w] == false) {
                if(p[w] > p[v] + G[v][w]) {
                    p[w] = p[v] + G[v][w];
                    pre1[w] = v;
                    num[w] = num[v] + t[v][w];
                } else if(p[w] == p[v] + G[v][w]) {
                    if(num[w] > num[v] + t[v][w]) {
                        pre1[w] = v;
                        num[w] = num[v] + t[v][w];
                    }
                }
            }
        }
    }
}
void dfs2(int v1) {
    fill(vis, vis + maxn, false);
    fill(p2, p2 + maxn, INF);
    fill(pre2, pre2 + maxn, -1);
    p2[v1] = 0;
    for(int j = 0; j < n; j++) {
        int min = INF, v = -1;
        for(int i = 0; i < n; i++) {
            if(min > p2[i] && vis[i] == false) {
                v = i;
                min = p2[i];
            }
        }
        if(v == -1) return;
        vis[v] = true;
        for(int w = 0; w < n; w++) {
            if(t[v][w] != INF && vis[w] == false) {
                if(p2[w] > p2[v] + t[v][w]) {
                    p2[w] = p2[v] + t[v][w];
                    pre2[w] = v;
                    num2[w] = num2[v] + 1;
                } else if(p2[w] == p2[v] + t[v][w]) {
                    if(num2[w] > num2[v] + 1) {
                        pre2[w] = v;
                        num2[w] = num2[v] + 1;
                    }
                }
            }
        }
    }
}
void getAns(vector<int> &ans, int pre[]) {
    int pos = v2;
    while(pos != -1) {
        ans.push_back(pos);
        pos = pre[pos];
    }
    if(ans.size() == 1) ans.push_back(v2);
    reverse(ans.begin(), ans.end());
}
void show(vector<int> ans) {
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " -> ";
        cout << ans[i];
    }
    cout << endl;
}
int main() {
    cin >> n >> m;
    fill(G[0], G[0] + maxn * maxn, INF);
    fill(t[0], t[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++) {
        int v1, v2, isOne, len, tim;
        cin >> v1 >> v2 >> isOne >> len >> tim;
        G[v1][v2] = len;
        t[v1][v2] = tim;
        if(isOne == 0) {
            G[v2][v1] = len;
            t[v2][v1] = tim;
        }
    }
    cin >> v1 >> v2;  
    dfs1(v1);
    dfs2(v1);
    vector<int> dis, ti;
    getAns(dis, pre1);
    getAns(ti, pre2);
    if(dis == ti) {
        cout << "Distance = " << p[v2] << "; Time = " << p2[v2] << ": ";
        show(dis);
    } else {
        cout << "Distance = " << p[v2] << ": ";
        show(dis);
        cout << "Time = " << p2[v2] << ": ";
        show(ti);
    }
    return 0;
}