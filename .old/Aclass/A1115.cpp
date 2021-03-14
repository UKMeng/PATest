#include <iostream> // BTS + DFS
#include <vector>
using namespace std;
struct node {
    int v;
    struct node *left, *right;
} ;
vector<int> num(1010);
int max_depth = -1;
node * build(node *root, int v) {
    if(root == NULL) {
        root = new node();
        root -> v = v;
        root -> right = NULL, root -> left = NULL;
    } else if(v <= root -> v ) {
        root -> left = build(root -> left, v);
    }  else {root -> right = build(root -> right, v);}
    return root;
}
void dfs(node * root, int depth) {
    if(root == NULL) {
        max_depth = max(depth, max_depth);
        return;
    }
    num[depth]++;
    dfs(root -> left, depth + 1);
    dfs(root -> right, depth + 1);
}
int main() {
    int n, t;
    cin >> n;
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        cin >> t;
        root = build(root, t);
    }
    dfs(root, 0);
    cout << num[max_depth - 1] << " + " << num[max_depth - 2] << " = " << num[max_depth - 1] + num[max_depth - 2];
    return 0;
}