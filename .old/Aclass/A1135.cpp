#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int data;
    node *left, *right;
};
vector<int> pre, in; 
bool cmp(int a, int b) {return abs(a) < abs(b);}
node *create(int pl, int pr, int il, int ir) {
    node *root = new node;
    if(pl > pr) return NULL;
    root -> data = pre[pl];
    int k;
    for(k = il; k <= ir; k++) if(pre[pl] == in[k]) break;
    int lnum = k - il;
    root -> left = create(pl + 1, pl + lnum, il, k - 1);
    root -> right = create(pl + lnum + 1, pr, k + 1, ir);
    return root;
}
bool judge1(node *root) {
    if(root == NULL) return true;
    if(root -> data < 0) {
        if(root -> left != NULL && root -> left -> data < 0) return false;
        if(root -> right != NULL && root -> right -> data <0) return false;
    }
    return judge1(root -> left) && judge1(root -> right);
}
int getNum(node *root) {
    if(root == NULL) return 0;
    int l = getNum(root -> left), r = getNum(root -> right);
    return root -> data > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *root) {
    if(root == NULL) return true;
    int l = getNum(root -> left), r = getNum(root -> right);
    if(l != r) return false;
    return judge2(root -> left) && judge2(root -> right);
}
int main() {
    int k, n;
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> n;
        pre.resize(n);
        for(int i = 0; i < n; i++) cin >> pre[i];
        in = pre;
        sort(in.begin(), in.end(), cmp);
        node *root = create(0, n - 1, 0, n - 1);
        if(pre[0] < 0 || judge1(root) == false || judge2(root) == false) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}