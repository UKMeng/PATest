#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// 建树+BFS

struct Node{
    int data;
    int level;
    Node* left;
    Node* right;
};

vector<int> pre, in;
unordered_map<int, int> pos_map;

Node* create_tree(int preL, int preR, int inL, int inR){
    if(preL > preR) return NULL;
    Node* root = new Node;
    root -> data = pre[preL];
    int pos = pos_map[root->data];
    int left_len = pos - inL;
    root -> left = create_tree(preL + 1, preL + left_len, inL, pos-1);
    root -> right = create_tree(preL + left_len + 1, preR, pos+1, inR);
    return root;
}

vector<int> BFS(Node* root){
    queue<Node*> q;
    vector<int> ans;
    int current_level = 0;
    root -> level = 1;
    q.push(root);
    while(!q.empty()){
        Node* now = q.front();
        q.pop();
        if(current_level != now->level){
            ans.push_back(now->data);
            current_level++;
        }
        if(now->left != NULL) {
            now -> left -> level = now -> level + 1;
            q.push(now->left);
        }
        if(now->right != NULL){
            now -> right -> level = now -> level + 1;
            q.push(now->right);
        }
    }
    return ans;
}

int main(){
    // input
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++){
        cin >> in[i];
        pos_map[in[i]] = i;
    }
    for(int i = 0; i < n; i++){cin >> pre[i];}

    // create a tree
    Node* root = create_tree(0, n-1, 0, n-1);

    // get an answer and output
    vector<int> ans = BFS(root);

    // output
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }

    return 0;
}