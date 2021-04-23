// 图 计算去掉一个点后图有几个连通分量
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > road;
vector<int> visit;

void dfs(int start){
    for(int i = 0; i < road[start].size(); i++){
        if(!visit[road[start][i]]){
            visit[road[start][i]] = 1;
            dfs(road[start][i]);
        }
    }
}
int main(){
    int m, n, k;
    cin >> m >> n >> k;   
    road.resize(m+1); 
    visit.resize(m+1);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        int ans = 0;
        fill(visit.begin(), visit.end(), 0);
        visit[c] = 1;
        for(int i = 1; i <= m; i++){
            if(!visit[i]){
                visit[i] = 1;
                dfs(i);
                ans++;
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}