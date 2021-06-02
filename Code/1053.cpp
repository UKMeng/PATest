#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, m, s;
unordered_map<int, int> value;
vector<vector<int>> leaf;
vector<vector<int>> path;
vector<int> tempPath;
int valueSum = 0;

void dfs(int node){
    if(valueSum > s) return;
    if(leaf[node].size() == 0){
        if(valueSum == s) {
            path.push_back(tempPath);
        }
    } else{
        for(int child: leaf[node]){
            valueSum += value[child];
            tempPath.push_back(child);
            dfs(child);
            valueSum -= value[child];
            tempPath.pop_back();
        }
    }
}

bool cmp(vector<int> a, vector<int> b){
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if(value[a[i]] != value[b[i]]) return value[a[i]] > value[b[i]];
    }
    return a.size() > b.size();  // 不能写return true 否则会出现段错误 排序函数必须对所有可能的情况做出处理，否则就可能出错
}

int main(){
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        value[i] = temp;
    }
    leaf.resize(n);
    for(int i = 0; i < m; i++){
        int father, num;
        scanf("%d %d", &father, &num);
        for(int j = 0; j < num; j++){
            int child;
            scanf("%d", &child);
            leaf[father].push_back(child);
        }
    }
    tempPath.push_back(0);
    valueSum = value[0];
    dfs(0);
    sort(path.begin(), path.end(), cmp);
    for(auto p: path){
        for(int i = 0; i < p.size(); i++){
            if(i != 0) cout << " " << value[p[i]];
            else cout << value[p[i]];
        }
        cout << endl;
    }
    return 0;
}