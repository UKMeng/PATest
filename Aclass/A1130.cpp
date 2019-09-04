#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct node {
    string s;
    int l, r;
} ;
vector<node> v;
int n, root = 1;
string dfs(int index) {
    if(index == -1) return "";
    if(v[index].r != -1) {
        v[index].s = dfs(v[index].l) + v[index].s + dfs(v[index].r);
        if(index != root) v[index].s = '(' + v[index].s +')' ;
    }
    return v[index].s;
}
int main() {
    cin >> n;
    v.resize(n + 1);
    vector<bool> visit(n + 1, false);
    for(int i = 1; i <= n; i++) {
        cin >> v[i].s >> v[i].l >> v[i].r;
        if(v[i].l != -1) visit[v[i].l] = true;
        if(v[i].r != -1) visit[v[i].r] = true;
    }
    while(visit[root] == true) root++; // 寻找根节点
    cout << dfs(root) << endl;
    return 0;
}