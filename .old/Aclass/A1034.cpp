#include <iostream> // DFS
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 1, G[2010][2010], weight[2010], head, totalW, gangNum;
map<int, string> idTable;
map<string, int> intTable;
bool vis[2010];
struct node {string h; int num; node(string h, int num) : h(h), num(num) {};};
vector<node> ans;
int getID(string a) {
    if(intTable[a] == 0) {
        idTable[cnt] = a;
        intTable[a] = cnt;
        cnt++;
    }
    return intTable[a];
}
void dfs(int a) {
    vis[a] = true;
    gangNum++;
    if(weight[a] > weight[head]) head = a;
    for(int i = 1; i < cnt; i++) {
        if(G[a][i] > 0) {
            totalW += G[a][i];
            G[a][i] = G[i][a] = 0;
            if(vis[i] == false) dfs(i);
        }
    }
}
bool cmp(node a, node b) {
    return a.h < b.h;
}
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        int t, id1, id2;
        cin >> s1 >> s2 >> t;
        id1 = getID(s1);
        id2 = getID(s2);
        G[id1][id2] += t;
        G[id2][id1] += t;
        weight[id1] += t;
        weight[id2] += t;
    }
    for(int i = 1; i < cnt; i++) {
        if(vis[i] == false) {
            head = i, gangNum = 0, totalW = 0;
            dfs(i);
            if(totalW > k && gangNum > 2) ans.push_back(node(idTable[head], gangNum));
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i].h << " " << ans[i].num << endl;
    return 0;
}