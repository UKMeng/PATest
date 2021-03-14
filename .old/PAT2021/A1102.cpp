#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ctoi(char a){
    if(a == '-') return -1;
    else return a - '0';
}

struct Node{
    int left, right;
} tree[30];

void BFS(int root){
    vector<int> level_order;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        level_order.push_back(t);
        if(tree[t].left != -1) q.push(tree[t].left);
        if(tree[t].right != -1) q.push(tree[t].right);
    }
    for(int i = 0; i < level_order.size(); i++){
        if(i != 0) cout << " " << level_order[i];
        else cout << level_order[i];
    }
    cout << endl;
}

vector<int> in_order;

void DFS(int root){
    if(tree[root].left != -1) DFS(tree[root].left);
    in_order.push_back(root);
    if(tree[root].right != -1) DFS(tree[root].right);
}

int main(){
    int n; 
    cin >> n;
    int root = 0;
    for(int i = 0; i < n; i++){
        root += i;
        char c1, c2;
        cin >> c1 >> c2;
        int l = ctoi(c1);
        int r = ctoi(c2);
        if(l != -1) root -= l;
        if(r != -1) root -= r;
        tree[i].left = r; // invert
        tree[i].right = l;
    }

    // BFS level-order
    BFS(root);

    // DFS in-order
    DFS(root);
    for(int i = 0; i < in_order.size(); i++){
        if(i != 0) cout << " " << in_order[i];
        else cout << in_order[i];
    }
    return 0;
}