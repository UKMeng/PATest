#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int v;
    struct node * left, * right;
    int depth;
}; 
int post[40], in[40];
node * build(int il, int ir, int pl, int pr) {
    if(il > ir) return NULL;
    node * root = new node;
    int pos;
    for(int i = il; i <= ir; i++) {
        if(in[i] == post[pr]) {
            pos = i;
            break;
        }
    }
    int llen = pos - il, rlen = ir - pos;
    root -> v = post[pr];
    root -> left = build(il, pos - 1, pl, pl + llen - 1);
    root -> right = build(pos + 1, ir, pl + llen, pr - 1);
    return root;
}
int maxdepth = -1;
vector<int> nodes[40];
void zz_levelOrder(node * root) {
    queue<node *> q;
    root -> depth = 0;
    q.push(root);
    while(!q.empty()) {
        node * temp = q.front();
        q.pop();
        maxdepth = max(maxdepth, temp -> depth);
        nodes[temp -> depth].push_back(temp -> v);
        if(temp -> left != NULL) {
            temp -> left -> depth = temp -> depth + 1;
            q.push(temp -> left);
        }
        if(temp -> right != NULL) {
            temp -> right -> depth = temp -> depth + 1;
            q.push(temp -> right);
        }
    }
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    node * root = build(0, n - 1, 0, n - 1);
    zz_levelOrder(root);
    bool first = true;
    for(int i = 0; i <= maxdepth; i++) {       // 对层序遍历中按题目要求排序
        if(i % 2 == 0) {
            for(int j = 0; j < nodes[i].size(); j++) {
                if(first) {
                    first = false;
                    cout << nodes[i][nodes[i].size() - 1 - j];
                } else cout << " " << nodes[i][nodes[i].size() - 1 - j];
            }
        } else {
            for(int j = 0; j < nodes[i].size(); j++) {
                cout << " " << nodes[i][j];
            }
        }
    }
    return 0;
}