#include <iostream>
#include <vector>
#include <set>
#include <unordered_map> 
using namespace std;

int G[210][210];
unordered_map<int, bool> mapp;
int n, m;
pair<int,int> dij(int start){
    vector<bool> visit(n+1, false);
    vector<int> dis(n+1, 0x3f3f3f3f);
    dis[start] = 0;
    int ne_id = -1;
    int ne_dis = 0x3f3f3f3f;
    for(int i = 0; i <= n; i++){
        int u = -1;
        int DIS_MIN = 0x3f3f3f3f;
        for(int j = 0; j <= n; j++){
            if(!visit[j] && DIS_MIN > dis[j]){
                u = j;
                DIS_MIN = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v <= n; v++){
            if(!visit[v] && G[u][v] != 0){
                if(dis[v] > dis[u] + G[u][v]){
                    dis[v] = dis[u] + G[u][v];
                    if(dis[v] < ne_dis && !mapp[v]){
                        ne_dis = dis[v];
                        ne_id = v;
                    } else if(dis[v] == ne_dis && !mapp[v]){
                        if(v < ne_id) ne_id = v;
                    }
                }
            }
        }
    }
    return make_pair(ne_id, ne_dis);
}

int main(){    
    scanf("%d %d", &n ,&m);    
    for(int i = 0; i < m ;i++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        G[a][b] = d;
        G[b][a] = d;
    }
    int start = 0;
    vector<int> ans;
    mapp[0] = true;
    ans.push_back(0);
    int sum_dis = 0;
    while(ans.size() < n+1){
        pair<int, int> ret = dij(start);
        // cout << ne;
        int ne = ret.first;
        if(ne == -1) break;
        mapp[ne] = true;
        int d = ret.second;
        sum_dis += d;
        ans.push_back(ne);
        start = ne;
    }
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    cout << endl;
    if(ans.size() == n+1) cout << sum_dis << endl;
    else{
        bool flag = true;
        for(int i = 0; i <= n; i++){
            if(!mapp[i]){
                if(flag){
                    cout << i;
                    flag =false;
                }else{
                    cout << " " << i;
                }
            }
        }
    }
    return 0;
}