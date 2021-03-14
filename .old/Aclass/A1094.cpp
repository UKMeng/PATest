#include <iostream>
#include <vector>
using namespace std;
const int maxn = 110;
struct node {
    vector<int> child;
} Node[maxn];
int layerNum[maxn];
void dfs(int root, int nowlayer) {
    layerNum[nowlayer]++;
    for(int i = 0; i < Node[root].child.size(); i++) dfs(Node[root].child[i], nowlayer + 1);
}
int main() {
    int n, m, maxnum = 0, maxlayer = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int tempid, tempnum;
        cin >> tempid >> tempnum;
        for(int j = 0; j < tempnum; j++) {
            int tempchild;
            cin >> tempchild;
            Node[tempid].child.push_back(tempchild);
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++) {
        if(layerNum[i] > maxnum) {
            maxnum = layerNum[i];
            maxlayer = i;
        }
    }
    cout << maxnum << " " << maxlayer;
    return 0;
}