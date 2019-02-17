#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n, cnt1 = 0, cnt2 = 0;
struct node{
    int lchild, rchild;
}Node[11];
int ctoi(char c) {
    if(c == '-') return -1;
    else return c - '0';
}
int findRoot() {
    set<int> s;
    for(int i = 0; i < n; i++) s.insert(i);
    for(int i = 0; i < n; i++) {
        if(Node[i].lchild != -1) s.erase(s.find(Node[i].lchild));
        if(Node[i].rchild != -1) s.erase(s.find(Node[i].rchild));
    }
    return *s.begin();
}
void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int newroot = q.front();
        q.pop();
        cnt1++;
        cout << newroot;
        if(cnt1 < n) cout << " ";
        int l = Node[newroot].lchild, r = Node[newroot].rchild;
        if(l != -1) q.push(l);
        if(r != -1) q.push(r);
    }
}
void inOrder(int root) {
    int l = Node[root].lchild, r = Node[root].rchild;
    if(l != -1) inOrder(l);
    cnt2++;
    cout << root;
    if(cnt2 < n) cout << " ";
    if(r != -1) inOrder(r);
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        Node[i].rchild = ctoi(c1);
        Node[i].lchild = ctoi(c2);
    }
    int root = findRoot();
    levelOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}