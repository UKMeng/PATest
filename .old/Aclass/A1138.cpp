#include <iostream>
#include <vector>
using namespace std;
struct node {
    node * left, * right;
    int id;
} ;
vector<int> pre, in;
node * create(int pl, int pr, int il, int ir) {
    if(pr < pl) return NULL;
    node * root = new node;
    int pos;
    for(int i = il; i <= ir; i++) {
        if(in[i] == pre[pl]) {
            pos = i;
            break;
        }
    }
    int llen = pos - il;
    root -> id = pre[pl];
    root -> left = create(pl + 1, pl + llen, il, pos - 1);
    root -> right = create(pl + llen + 1, pr, pos + 1, ir);
    return root;
}
int findid(node * root) {
    while(root -> left != NULL || root -> right != NULL) {
        if(root -> left != NULL) root = root -> left;
        else if(root -> right != NULL) root = root -> right;
    }
    return root -> id;
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    node * root = new node;
    root = create(0, n - 1, 0, n - 1);
    int ans = findid(root);
    cout << ans;
    return 0;
}