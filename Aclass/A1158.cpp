#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct UnionFind {
    vector<int> id;
    vector<int> sz;
    UnionFind(int n) : id(n), sz(n, 1) {
        for(int i = 0; i < n; i++) id[i] = i;
    }
    int Find(int x) {
        if(id[x] == x) return x;
        return id[x] = Find(id[x]);
    }
    void Union(int x, int y) {
        int i = Find(x);
        int j = Find(y);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; 
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
} ;
bool cmp(vector<int> a, vector<int> b) {
    return a.front() < b.front();
}
int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int> > durations(n + 1, vector<int>(n + 1));
    while(m--){
        int c, r, d;
        cin >> c >> r >> d;
        durations[c][r] += d;
    }
    vector<int> suspects;
    for(int i = 1; i <= n; i++) {
        int count = 0, callBack = 0;
        for(int j = 1; j <= n; j++) {
            if(durations[i][j] > 0 && durations[i][j] <= 5) {
                count++;
                callBack += (durations[j][i] != 0);
            }
        }
        if(count > k && callBack <= 0.2 * count) suspects.push_back(i);
    }
    if(suspects.empty()) {
        cout << "None" << endl;
        return 0;
    }
    UnionFind uf(n + 1);
    for(int i = 0; i < suspects.size(); i++) {
        for(int j = i + 1; j < suspects.size(); j++) {
            if(durations[suspects[i]][suspects[j]] != 0 && durations[suspects[j]][suspects[i]]) uf.Union(suspects[i], suspects[j]);
        }
    }
    vector<int> temp[n + 1];
    for(auto it : suspects) {
        temp[uf.Find(it)].push_back(it);
    }
    vector<vector<int> > ans;
    for(auto it : temp) {
        if(!it.empty()) {
            ans.push_back(it);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for(auto it : ans) {
        for(int i = 0; i < it.size(); i++) {
            cout << it[i] << (i < it.size() - 1 ? " " : "\n");
        }
    }
    return 0;
}