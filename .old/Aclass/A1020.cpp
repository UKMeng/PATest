#include <iostream>
#include <queue>
using namespace std;
const int maxn = 35;
int post[maxn], in[maxn], n;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
node* ans;
node* create(int postl, int postr, int inl, int inr) {
    if(postl > postr) return NULL;
    node* root = new node;
    root -> data = post[postr];
    int k;
    for(k = inl; k <= inr; k++) if(post[postr] == in[k]) break;
    int lnum = k - inl;
    root -> lchild = create(postl, postl + lnum - 1, inl, inl + lnum - 1);
    root -> rchild = create(postl + lnum, postr - 1, k + 1, inr);
    return root;
}
void layerOrder(node* root) {
    queue<node*> q;
    q.push(root);
    int num = 0;
    while(!q.empty()) {
        node* now = q.front();
        q.pop();
        cout << now -> data;
        num++;
        if(num < n) cout << " ";
        if(now -> lchild != NULL) q.push(now -> lchild);
        if(now -> rchild != NULL) q.push(now -> rchild);
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> post[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    ans = create(0, n - 1, 0, n - 1);
    layerOrder(ans);
    return 0;
}