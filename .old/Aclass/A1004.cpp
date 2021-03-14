#include <iostream>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> ans;
struct node {
    vector<int> child;
} Node[maxn];
void dfs(int root, int level) {
    if(level > ans.size()) ans.push_back(0);
    if(Node[root].child.size() == 0) ans[level-1]++;
    for(int i = 0; i < Node[root].child.size(); i++) dfs(Node[root].child[i], level + 1);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int id, childnum;
        cin >> id >> childnum;
        for(int j = 0; j < childnum; j++) {
            int tempid;
            cin >> tempid;
            Node[id].child.push_back(tempid);
        }
    }
    dfs(1, 1);
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}