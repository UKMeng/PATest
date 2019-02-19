#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
struct node {
    int lchild, rchild, data;
} Node[maxn];
int n, input[maxn], cnt = 0, cnt1 = 0;
void inorder(int root) {
    if(Node[root].lchild != -1) inorder(Node[root].lchild);
    Node[root].data = input[cnt++];
    if(Node[root].rchild != -1) inorder(Node[root].rchild);
}
void levelorder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << Node[temp].data;
        cnt1++;
        if(cnt1 < n) cout << " ";
        if(Node[temp].lchild != -1) q.push(Node[temp].lchild);
        if(Node[temp].rchild != -1) q.push(Node[temp].rchild);
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> Node[i].lchild >> Node[i].rchild;
    for(int i = 0; i < n; i++) cin >> input[i];
    sort(input, input + n);
    inorder(0);
    levelorder(0);
    return 0;
}