#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Node{
    int left, right;
    int index;
} tree[30];

int record[30];
int n;
int last_node;

void BFS(int root){
    queue<int> q;
    q.push(root);
    tree[root].index = 0;
    while(!q.empty()){
        int t = q.front();
        last_node = t;
        int ti = tree[t].index;
        record[ti] = 1;
        q.pop();
        int l = tree[t].left;
        int r = tree[t].right;
        if(l != -1) {
            tree[l].index = ti * 2 + 1;
            q.push(l);
        }
        if(r != -1) {
            tree[r].index = ti * 2 + 2;
            q.push(r);
        }
    }
}

int main(){
    // output
    vector<int> is_root(30);
    int root = -1;
    cin >> n;
    for(int i = 0; i < n; i++){
        string tl, tr;
        int l, r;
        cin >> tl >> tr;
        if(tl == "-") l = -1;
        else {
            l = stoi(tl);
            is_root[l] = 1;
        }
        if(tr == "-") r = -1;
        else {
            r = stoi(tr);
            is_root[r] = 1;
        }
        if(l == -1 && r == -1) is_root[i] = -1;
        tree[i].left = l;
        tree[i].right = r;        
    }

    // find the root index
    for(int i = 0; i < n; i++){
        if(is_root[i] == 0) {
            root = i;
            break;
        }
    }

    // BFS
    BFS(root);

    
    for(int i = 0; i < n; i++){
        if(record[i] != 1) {
            cout << "NO" << " " << root;
            return 0;
        }
    }
    cout << "YES" << " " << last_node;
    return 0;
}