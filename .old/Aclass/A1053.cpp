#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, sum, ansnum = 0;
vector<int> weight, ans[110];
struct node {
    vector<int> child;
} Node[110];
bool cmp(vector<int> a, vector<int> b) {
    for(int i = 0; i < min(a.size(), b.size()); i++) {
        if(a[i] == b[i]) continue;
        else return a[i] > b[i];
    }
}
void dfs(int root, int tempsum, vector<int> temp) {
    tempsum += weight[root];
    temp.push_back(weight[root]);
    if(tempsum > sum) return;
    if(Node[root].child.size() == 0) {
        if(tempsum == sum) {ans[ansnum++] = temp; return;}
        else return;
    }
    for(int i = 0; i < Node[root].child.size(); i++) dfs(Node[root].child[i], tempsum, temp);
}
int main() {
    cin >> n >> m >> sum;
    weight.resize(n);
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < m; i++) {
        int id, childnum;
        cin >> id >> childnum;
        for(int j = 0; j < childnum; j++)  {
            int temp;
            cin >> temp;
            Node[id].child.push_back(temp);
        }
    }
    vector<int> temppath;
    dfs(0, 0, temppath);
    sort(ans, ans + ansnum, cmp);
    for(int i = 0; i < ansnum; i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            if(j != 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}