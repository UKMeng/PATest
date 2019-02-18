#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    vector<int> child;
} Node[maxn];
int n, maxNum = 0, maxLayer = -1;
double p, r, hp;
void dfs(int root, int nowLayer) {
    if(Node[root].child.size() == 0) {
        if(nowLayer > maxLayer) {
            maxLayer = nowLayer;
            maxNum = 1;
        }
        else if(nowLayer == maxLayer) maxNum++;
        return;
    }
    else for(int i = 0; i < Node[root].child.size(); i++) dfs(Node[root].child[i], nowLayer + 1);
}
int main() {
    int root;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp == -1) root = i;
        else Node[temp].child.push_back(i);
    }
    dfs(root, 0);
    hp = p;
    for(int i = 0; i < maxLayer; i++) hp *= (100.0 + r) / 100.0;
    printf("%.2f %d", hp, maxNum);
    return 0;
}