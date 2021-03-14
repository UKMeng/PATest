#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 40;
int pre[maxn], in[maxn], cnt1 = 0, n;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
node* create(int pl, int pr, int il, int ir) {
    if(pl > pr) return NULL;
    node* root = new node;
    root -> data = pre[pl];
    int k;
    for(k = il; k <= ir; k++) if(pre[pl] == in[k]) break;
    int lnum = k - il, rnum = ir - k;
    root -> lchild = create(pl + 1, pl + lnum, il, k - 1);
    root -> rchild = create(pl + lnum + 1, pr, k + 1, ir);
    return root;
}
void postOrder(node* root) {
    if(root == NULL) return;
    postOrder(root -> lchild);
    postOrder(root -> rchild);
    cnt1++;
    cout << root -> data;
    if(cnt1 < n) cout << " ";
}
int main() {
    int cnt = 0, pnum = 0, inum = 0;
    stack<int> q;
    cin >> n;
    while(n > cnt) {
        string s;
        cin >> s;
        if(s == "Push") {
            int t;
            cin >> t;
            q.push(t);
            pre[pnum++] = t;
        }
        else if(s == "Pop") {
            cnt++;
            in[inum++] = q.top();
            q.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}