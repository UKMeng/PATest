#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
struct node {
    int v, level;
    node * parent, * lchild, * rchild;
};
map<int, node *> mapp;
vector<int> post, in;
node * build(int pl, int pr, int il, int ir) {
    if(pl > pr) return NULL;
    node * root = new node();
    root -> v = post[pr];
    mapp[post[pr]] = root;
    int pos;
    for(pos = il; pos <= ir; pos++) {
        if(in[pos] == post[pr]) break;
    }
    int lnum = pos - il;
    root -> lchild = build(pl, pl + lnum - 1, il, pos - 1);
    root -> rchild = build(pl + lnum, pr - 1, pos + 1, ir);
    if(root -> lchild) root -> lchild -> parent = root;
    if(root -> rchild) root -> rchild -> parent = root;
    return root;
}
bool isFull = true;
void dfs(node * root) {
    if(!root) return;
    if(root -> parent) root -> level = root -> parent -> level + 1;
    if(root -> lchild && !root -> rchild) isFull = false;
    if(root -> rchild && !root -> lchild) isFull = false;
    dfs(root -> lchild);
    dfs(root -> rchild);
}
int main() {
    int n, k;
    scanf("%d", &n);
    post.resize(n), in.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    node * root = build(0, n - 1, 0, n - 1);
    dfs(root);
    scanf("%d", &k);
    getchar();
    while(k--) {
        string statement;
        bool flag;
        int a, b;
        getline(cin, statement);
        if(statement.find("root") != string::npos) {
            sscanf(statement.c_str(), "%d is the root", &a);
            flag = (a == root -> v);
        } else if(statement.find("siblings") != string::npos) {
            sscanf(statement.c_str(), "%d and %d are siblings", &a, &b);
            flag = (mapp[a] -> parent == mapp[b] -> parent);
        } else if(statement.find("parent") != string :: npos) {
            sscanf(statement.c_str(), "%d is the parent of %d", &a, &b);
            flag = (mapp[b] -> parent -> v == a);
        } else if(statement.find("left child") != string::npos) {
            sscanf(statement.c_str(), "%d is the left child of %d", &a, &b);
            // if(mapp[b] -> lchild) flag = (mapp[b] -> lchild -> v == a);
            // else flag = false;
            flag = (mapp[b] -> lchild == mapp[a]);
        } else if(statement.find("right child") != string::npos) {
            sscanf(statement.c_str(), "%d is the right child of %d", &a, &b);
            // if(mapp[b] -> rchild) flag = (mapp[b] -> rchild -> v == a);
            //e lse flag = false;
            flag = (mapp[b] -> rchild == mapp[a]);
        } else if(statement.find("same level") != string::npos) {
            sscanf(statement.c_str(), "%d and %d are on the same level", &a, &b);
            flag = (mapp[a] -> level == mapp[b] -> level);
        } else {
            flag = isFull;
        }
        printf("%s\n", flag == true ? "Yes" : "No");
    }
    return 0;
}