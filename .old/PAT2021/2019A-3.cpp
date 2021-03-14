#include <iostream>
using namespace std;

struct Node{
    string val;
    int l, r;
} Node[30];

string dfs(int root){
    if(Node[root].l == -1 && Node[root].r == -1) {
        return "(" + Node[root].val + ")";
    }
    else if(Node[root].l == -1 && Node[root].r != -1){
        return  "(" + Node[root].val + dfs(Node[root].r) + ")";
    }
    else{
        return "(" + dfs(Node[root].l) + dfs(Node[root].r) + Node[root].val + ")";
    }
}

int main(){
    int n;
    cin >> n;
    int root = 0;
    for(int i = 1; i < n+1; i++){
        root += i;
        string val;
        int l, r;
        cin >> val >> l >> r;
        if(l != -1) root -= l;
        if(r != -1) root -= r;
        Node[i].val = val;
        Node[i].l = l;
        Node[i].r = r;
    }
    string ans = dfs(root);
    cout << ans << endl;
    return 0;
}