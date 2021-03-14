#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int S[1010][1010], D[1010][1010];
vector<vector<int>> path;
vector<int> inDegreeCount;
queue<int> zeroInDegree;

vector<int> c;
bool dfs_c(int u, int n){
    c[u] = -1;
    for(int v = 0; v < n; v++){
        if(S[u][v] != 0){
            if(c[v] < 0) return false;
            else if(!c[v] && !dfs_c(v, n)) return false;
        } 
    }
    c[u] = 1;
    return true;
}

bool checkTopo(int n, vector<int> inDegree){
    c.resize(n);
    for(int i = 0; i < n; i++){
        if(!dfs_c(i, n)) return false;
    }
    return true;
}

vector<int> pre;
void Dijkstra(int n){
    for(int i = 0; i < n; i++){
        if(inDegreeCount[i] == 0){
            S[n][i] = 0;
            D[n][i] = 0;
            path[n].push_back(i);
        }
    }
    vector<int> dis(n+1, 0x3f3f3f3f);
    vector<int> cost(n+1);
    pre.resize(n+1);
    vector<bool> visit(n+1, false);
    dis[n] = 0;
    for(int i = 0; i <= n; i++){
        int MIN_DIS = 0x3f3f3f3f;
        int u = -1;
        for(int j = 0; j <= n; j++){
            if(!visit[j] && dis[j] < MIN_DIS){
                u = j;
                MIN_DIS = dis[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        //cout << "u = " << u << endl;
        for(int j = 0; j < path[u].size(); j++){
            int v = path[u][j];
            //cout << "v = " << v << endl;
            if(!visit[v]){
                if(dis[v] > dis[u] + S[u][v]){
                    dis[v] = dis[u] + S[u][v];
                    pre[v] = u;
                    cost[v] = cost[u] + D[u][v];
                } else if(dis[v] == dis[u] + S[u][v] && cost[v] < cost[u] + D[u][v]){
                    cost[v] = cost[u] + D[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

void dfs(int i, int n){
    if(pre[i] == n) cout << i;
    else {
        dfs(pre[i], n);
        cout << "->" << i;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    inDegreeCount.resize(n);
    path.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b, s, d;
        scanf("%d %d %d %d", &a, &b, &s, &d);
        S[a][b] = s;
        D[a][b] = d;
        path[a].push_back(b);
        inDegreeCount[b]++;
    }
    for(int i = 0; i < n; i++){
        if(inDegreeCount[i] == 0) zeroInDegree.push(i);
    }
    bool flag = checkTopo(n, inDegreeCount);
    int k;
    scanf("%d", &k);
    vector<int> query(k);
    for(int i = 0; i < k; i++){
        scanf("%d", &query[i]);
    }
    if(flag) {
        cout << "Okay." << endl;
        Dijkstra(n);
        for(int i = 0; i < k; i++){
            if(inDegreeCount[query[i]] == 0){
                cout << "You may take test " << query[i] << " directly." << endl;
            } else{
                dfs(query[i], n);
                cout << endl;
            }
        }
    }
    else{
        cout << "Impossible." << endl;
        for(int i = 0; i < k; i++){
            if(inDegreeCount[query[i]] == 0){
                cout << "You may take test " << query[i] << " directly." << endl;
            } else{
                cout << "Error." << endl;
            }
        }
    }
    return 0;
}