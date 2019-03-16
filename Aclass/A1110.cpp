#include <iostream>
using namespace std;
struct node {
    int left, right;
} tree[30];
bool isRoot[30];
int maxn = -1, ans;
void dfs(int now, int index) {
    if(index > maxn) {
        maxn = index;
        ans = now;
    }
    if(tree[now].left != -1) dfs(tree[now].left, index * 2);
    if(tree[now].right != -1) dfs(tree[now].right, index * 2 + 1);
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if(a == "-") tree[i].left = -1;
        else {
            tree[i].left = stoi(a);
            isRoot[stoi(a)] = true;
        }
        if(b == "-") tree[i].right = -1;
        else {
            tree[i].right = stoi(b);
            isRoot[stoi(b)] = true;
        }
    }
    int root;
    for(root = 0; root < n; root++) if(isRoot[root] == false) break;
    dfs(root, 1);
    if(maxn == n) cout << "YES " << ans;
    else cout << "NO " << root;
    return 0;
}