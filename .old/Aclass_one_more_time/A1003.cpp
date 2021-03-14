#include <iostream>
#include <vector>
using namespace std;
int dis[510][510];
int vis[510];
int startc, endc;
vector<int> res;
vector<int> G[510];
int num_spaths = 0, sdis = 9999999, max_res = 0, temp_res, temp_dis = 0;
void dfs(int now){
    //cout << now << " " << temp_res << " " << temp_dis << " " << num_spaths << endl;
    if(now == endc){
        if(temp_dis < sdis){
            sdis = temp_dis;
            num_spaths = 1;
            max_res = temp_res;
        } else if(temp_dis == sdis){
            num_spaths += 1;
            if(max_res < temp_res) max_res = temp_res;
        }
        return;
    }
    for(int i = 0; i < G[now].size(); i++){
        int nextc = G[now][i];
        if(vis[nextc] == 0){
            vis[nextc] = 1;
            temp_res += res[nextc];
            temp_dis += dis[now][nextc];
            dfs(nextc);
            temp_res -= res[nextc];
            temp_dis -= dis[now][nextc];
            vis[nextc] = 0;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m >> startc >> endc;
    res.resize(n);
    for(int i = 0; i < n; i++){
        cin >> res[i];
    }
    for(int i = 0; i < m; i++){
        int c1, c2, p;
        cin >> c1 >> c2 >> p;
        G[c1].push_back(c2);
        G[c2].push_back(c1);
        dis[c1][c2] = p;
        dis[c2][c1] = p;
    }
    vis[startc] = 1;
    temp_res = res[startc];
    dfs(startc);
    cout << num_spaths << " " << max_res << endl;
    return 0;
}