#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> visit;
vector<vector<int>> G;
vector<int> ans;
int maxDepth = 0;
int tempMaxDepth = 0;

void dfs(int index, int depth){
    for(int i = 0; i < G[index].size(); i++){
        if(visit[G[index][i]] == 0){
            visit[G[index][i]] = 1;
            dfs(G[index][i], depth+1);
        }
    }
    tempMaxDepth = max(tempMaxDepth, depth);
}

int main(){
    // 接受输入
    int n;
    cin >> n;
    G.resize(n+1);
    visit.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 计算连通分量
    int componentsCount = 0;
    for(int i = 1; i < n+1; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            dfs(i, 0);
            componentsCount++;
        }
    }
    if(componentsCount != 1){
        cout << "Error: " << componentsCount << " components" << endl;
    } else{     // DFS寻找最深根
        for(int i = 1; i < n+1; i++){
            fill(visit.begin(), visit.end(), 0);
            tempMaxDepth = 0;
            visit[i] = 1;
            dfs(i, 1);
            if(tempMaxDepth > maxDepth){
                maxDepth = tempMaxDepth;
                ans.clear();
                ans.push_back(i);
            } else if(tempMaxDepth == maxDepth){
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}