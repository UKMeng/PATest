#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
vector<pair<int, int>> table;
vector<vector<int>> v;
int temp_ans = 0;
void dfs(int i, int j){
    if(v[i].size() == 0){
        temp_ans = max(temp_ans, j);
        return;
    }
    for(int c = 0; c < v[i].size(); c++){
        dfs(v[i][c], j+1);
    }
}

int main(){
    int n;
    scanf("%d", &n);    
    for(int i = 0; i < n; i++){
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int t1, t2;
        t1 = h1 * 3600 + m1 * 60 + s1;
        t2 = h2 * 3600 + m2 * 60 + s2;
        table.push_back(make_pair(t1, t2));
    }
    sort(table.begin(), table.end(), cmp);
    v.resize(n);
    for(int i = 0; i < table.size(); i++){
        int j = i + 1;
        for(;j < table.size(); j++){
            if(table[j].first >= table[i].second){
                break;
            }
        }
        for(int c = j; c < table.size(); c++){
            v[i].push_back(c);
        }
    }
    int ans = 0;
    for(int i = 0; i < table.size(); i++){
        if(v[i].size() == 0) continue;
        dfs(i, 1);
    }   
    cout << temp_ans;
    return 0;
}

/*
7
18:00:01 23:07:01
04:09:59 11:30:08
11:35:50 13:00:00
23:45:00 23:55:50
13:00:00 17:11:22
06:30:50 11:42:01
17:30:00 23:50:00
*/