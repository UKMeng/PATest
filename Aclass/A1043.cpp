#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pre, in, temp;
bool cmp(int a, int b) {return a > b;}
bool flag = true, isMirror = false;
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
    if(isMirror) {for(k = ir; k >= il; k--) if(pre[pl] == in[k]) break;}
    else for(k = il; k <= ir; k++) if(pre[pl] == in[k]) break;
    if(pre[pl] != in[k]) {flag = false; return NULL;}
    int lnum = k - il;
    root -> lchild = create(pl + 1, pl + lnum, il, k - 1);
    root -> rchild = create(pl + lnum + 1, pr, k + 1, ir);
    return root;
}
int n, tempnum = 0;
void postorder(node* root) {
    if(root == NULL) return;
    postorder(root -> lchild);
    postorder(root -> rchild);
    tempnum++;
    cout << root -> data;
    if(n > tempnum) cout << " ";
}
int main() {
    cin >> n;
    temp.resize(n);
    for(int i = 0; i < n; i++) cin >> temp[i];
    pre = temp;
    pre.push_back(-1);
    pre.insert(pre.begin(), -1);
    if(temp[0] > temp[1]) sort(temp.begin(), temp.end());
    else {sort(temp.begin(), temp.end(), cmp); isMirror = true;}
    in = temp;
    in.push_back(-1);
    in.insert(in.begin(), -1);
    node* root = create(1, n, 1, n);
    if(!flag) cout << "NO";
    else {
        cout << "YES" << endl;
        postorder(root);
    }
    return 0;
}