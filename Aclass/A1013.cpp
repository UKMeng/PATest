#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m, k, conqid;
vector<int> G[maxn];
bool isv[maxn];
void dfs(int v) {
    if(v == conqid) return;
    isv[v] = true;
    for(int i = 0; i < G[v].size(); i++) {
        if(isv[G[v][i]] == false) dfs(G[v][i]);
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int id1, id2;
        cin >> id1 >> id2;
        G[id1].push_back(id2);
        G[id2].push_back(id1);
    }
    for(int i = 0; i < k; i++) {
        cin >> conqid;
        int block = 0;
        memset(isv, false, sizeof(isv));
        for(int i = 1; i <= n; i++) {
            if(i != conqid && isv[i] == false) {
                dfs(i);
                block++;
            }
        }
        cout << block - 1 << endl;
    }
    return 0;
}