#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    vector<int> child;
} Node[maxn];
int n, minNum = 0, minLayer = maxn;
double p, r, hp;
void dfs(int root, int nowLayer) {
    if(Node[root].child.size() == 0) {
        if(nowLayer < minLayer) {
            minLayer = nowLayer;
            minNum = 1;
        }
        else if(nowLayer == minLayer) minNum++;
        return;
    }
    else for(int i = 0; i < Node[root].child.size(); i++) dfs(Node[root].child[i], nowLayer + 1);
}
int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        for(int j = 0; j < temp; j++) {
            int t;
            scanf("%d", &t);
            Node[i].child.push_back(t);
        }
    }
    dfs(0, 0);
    hp = p;
    for(int i = 0; i < minLayer; i++) hp *= (100.0 + r) / 100.0;
    printf("%.4f %d", hp, minNum);
    return 0;
}