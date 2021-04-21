#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> child){
    int now_level = 1;
    int level_count = 0;
    queue<pair<int, int>> q; // first-id second-level
    vector<int> ans;
    q.push({1, 1});
    while(!q.empty()){
        pair<int, int> temp = q.front(); q.pop();
        if(now_level != temp.second){
            now_level = temp.second;
            ans.push_back(level_count);
            level_count = 0;
        }
        if(child[temp.first].size() == 0) level_count++;
        else{
            for(int i = 0; i < child[temp.first].size(); i++){
                q.push({child[temp.first][i], temp.second+1});
            }
        }
    }
    ans.push_back(level_count);
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n == 0) return 0;
    vector<vector<int>> child(n+1);
    for(int i = 0; i < m; i++){
        int a, num;
        cin >> a >> num;
        for(int j = 0; j < num; j++){
            int b;
            cin >> b;
            child[a].push_back(b);
        }
    }
    bfs(child);
    return 0;
}