#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int G[1010][1010];
vector<vector<int>> lessk;
vector<unordered_set<int>> record;
vector<int> s;
unordered_set<int> s_i;

// union find
vector<int> f, r;
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

void union_set(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx != fy){
        if(r[fx] < r[fy]){
            swap(fx, fy);
        }
        r[fx] += r[fy];
        f[fy] = fx;
    }
}


int main(){
    // input
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    lessk.resize(n+1);
    record.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        G[a][b] += t;
        record[a].insert(b);
    }
    for(int i = 1; i < n + 1; i++){
        unordered_set<int> temp = record[i];
        if(temp.size() <= k) continue;
        else{
            int count = 0;
            for(int num:temp){
                if(G[i][num] <= 5){
                    lessk[i].push_back(num);
                    if(lessk[i].size() > k) s_i.insert(i);
                }
            }
        }
    }
    for(int index:s_i){
        int total = lessk[index].size(), count = 0;
        for(int i = 0; i < total; i++){
            int ri = lessk[index][i];
            if(G[ri][index] != 0) count++;
        }
        if(count * 5 <= total) s.push_back(index);
    }
    if(s.size() == 0) cout << "None" << endl;
    else{
        if(s.size() == 1){
            cout << s[0] << endl;
            return 0;
        }
        f.resize(n+1);
        r.resize(n+1, 1);
        for(int i = 1; i < n+1; i++) f[i] = i;
        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j < s.size(); j++){
                if(G[s[i]][s[j]] != 0 && G[s[j]][s[i]] != 0){
                    union_set(s[i], s[j]);
                }
            }
        }
        vector<vector<int>> ans, temp;
        unordered_set<int> father;
        temp.resize(n+1);
        for(int i = 0; i < s.size(); i++){
            int fa = find(s[i]);
            father.insert(fa);
            temp[fa].push_back(s[i]);
        }
        for(int fa:father){
            vector<int> t = temp[fa];
            sort(t.begin(), t.end());
            ans.push_back(t);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                if(j != 0) cout << " " << ans[i][j];
                else cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}