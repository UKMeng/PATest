#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> weight;

// dijkstra
void dijkstra(int start, int end, vector<int> weight, vector<vector<int>> G, int& count, int& max_res){
    int n = weight.size();
    vector<bool> visit(n);
    vector<int> dis(n, 0x3f3f3f3f);
    vector<int> res(n);
    vector<int> path_num(n);
    dis[start] = 0;
    res[start] = weight[start];
    path_num[start] = 1;
    for(int i = 0; i < n; i++){
        int MIN_DIS = 0x3f3f3f3f;
        int u = -1;
        for(int j = 0; j < n; j++){
            if(!visit[j] && dis[j] < MIN_DIS){
                u = j;
                MIN_DIS = dis[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        for(int v = 0; v < n; v++){
            if(!visit[v] && G[u][v] != 0){
                if(dis[v] > dis[u] + G[u][v]){
                    dis[v] = dis[u] + G[u][v];
                    res[v] = weight[v] + res[u];
                    path_num[v] = path_num[u];
                } else if(dis[v] == dis[u] + G[u][v]){
                    res[v] = max(res[v], weight[v] + res[u]);
                    path_num[v] += path_num[u];
                }
            }
        }
    }
    count = path_num[end];
    max_res = res[end];
    return;
}

// dfs
vector<vector<pair<int, int>>> edge;
vector<bool> visit_dfs;
int temp_res = 0;
int temp_dis = 0;
int min_temp_dis = 0x3f3f3f3f;
void dfs(int start, int end, int& count, int& max_res){
    if(start == end){
        temp_res += weight[end];
        if(temp_dis < min_temp_dis){
            min_temp_dis = temp_dis;
            count = 1;
            max_res = temp_res;
        } else if(temp_dis == min_temp_dis){
            count++;
            max_res = max(max_res, temp_res);
        }
        temp_res -= weight[end];
        return;
    }
    for(int i = 0; i < edge[start].size(); i++){
        int v = edge[start][i].first;
        int dis = edge[start][i].second;
        if(!visit_dfs[v]){
            visit_dfs[start] = true;
            temp_res += weight[start];
            temp_dis += dis;
            dfs(v, end, count, max_res);
            visit_dfs[start] = false;
            temp_res -= weight[start];
            temp_dis -= dis;
        }
    }
}


int main(){
    int n, m, start, end;
    int count = 0; // 记录最短路径数量
    int max_res = 0; // 记录最大救援队数量
    cin >> n >> m >> start >> end;
    weight.resize(n);
    edge.resize(n);
    visit_dfs.resize(n);
    vector<vector<int>> G(n, weight);
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a][b] = w;
        G[b][a] = w;
        edge[a].push_back({b,w});
        edge[b].push_back({a,w});
    }
    dijkstra(start, end, weight, G, count, max_res);
    cout << "dijkstra " << count << " " << max_res << endl;
    count = 0;
    max_res = 0;
    dfs(start, end, count, max_res);
    cout << "dfs " << count << " " << max_res << endl;
    return 0;
}