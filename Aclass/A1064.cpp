#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
vector<int> input;
int n, cnt = 0;
int findroot(int n) {
    if(n == 0) return -1;
    if(n == 1) return 0;
    int t = 1, init = 1;
    while(t < n) {init *= 2; t += init;}
    if(n - init < init / 2) return init / 2 + (n - init);
    else return init - 1;
}
node* create(int rootid, int il, int ir) {
    if(il > ir) return NULL;
    node* root = new node;
    root -> data = input[rootid];
    root -> lchild = create(il + findroot(rootid - il), il, rootid - 1);
    root -> rchild = create(rootid + 1 + findroot(ir - rootid), rootid + 1, ir);
    return root;
}
void levelorder(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp -> data;
        cnt++;
        if(cnt < n) cout << " ";
        if(temp -> lchild != NULL) q.push(temp -> lchild);
        if(temp -> rchild != NULL) q.push(temp -> rchild);
    }
}
int main() {
    cin >> n;
    input.resize(n);
    for(int i = 0; i < n; i++) cin >> input[i];
    sort(input.begin(), input.end());
    int rootid = findroot(n);
    node* root = create(rootid, 0, n - 1);
    levelorder(root);
    return 0;
}