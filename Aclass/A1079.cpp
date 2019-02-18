#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    double price;
    int amount;
    vector<int> child;
} Node[maxn];
int n;
double p, r, ans = 0.0;
void dfs(int root, double nowp) {
    Node[root].price = nowp;
    double nextprice = nowp * ((100.0 + r) / 100.0);
    if(Node[root].child.size() == 0) {
        ans += Node[root].price * Node[root].amount;
        return;
    }
    else {
        for(int i = 0; i < Node[root].child.size(); i++) dfs(Node[root].child[i], nextprice);
    }
}
int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp == 0) scanf("%d", &Node[i].amount);
        else {
            for(int j = 0; j < temp; j++) {
                int t;
                scanf("%d", &t);
                Node[i].child.push_back(t);
            }
        }
    }
    dfs(0, p);
    printf("%.1f", ans);
    return 0;
}