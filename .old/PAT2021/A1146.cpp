#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> level;
void bfs(vector<int> inDegree, vector<vector<int>> path, int n){
    level.resize(n+1);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0){
            q.push(i);
            level[i] = 1;
        }
    }
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j = 0; j < path[i].size(); j++){
            int index = path[i][j];
            inDegree[index]--;
            if(inDegree[index] == 0) {
                q.push(index);
                level[index] = level[i] + 1;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> inDegree(n+1);
    vector<vector<int>> path(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        inDegree[b]++;
    }
    bfs(inDegree, path, n);
    int k;
    cin >> k;
    vector<int> ans;
    for(int i = 0; i < k; i++){
        vector<int> temp(n);
        for(int j = 0; j < n; j++){
            cin >> temp[j];
        }
        vector<int> t(inDegree);
        for(int j = 0; j < n; j++){
            if(t[temp[j]] != 0){
                ans.push_back(i);
                break;
            } else{
                for(int index:path[temp[j]]){
                    t[index]--;
                }
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    return 0;
}