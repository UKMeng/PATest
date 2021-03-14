#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int val;
    int level;
};
unordered_map<int, int> pos;
vector<int> pre, in;

Node* create(int pl, int pr, int il, int ir){
    if(pl > pr) return nullptr;
    Node* root = new Node();
    root->val = pre[pl];
    int p = pos[root->val];
    int llen = p - il;
    root->left = create(pl+1, pl+llen, il, p-1);
    root->right = create(pl+llen+1, pr, p+1, ir);
    return root;
}

vector<int> ans;
void bfs(Node* root){
    queue<Node*> q;
    root->level = 1;
    q.push(root);
    int nowlevel = 0;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->level != nowlevel){
            nowlevel = temp->level;
            ans.push_back(temp->val);
        }
        if(temp->left!=nullptr){
            temp->left->level = temp->level + 1;
            q.push(temp->left);
        }
        if(temp->right!=nullptr){
            temp->right->level = temp->level + 1;
            q.push(temp->right);
        }
    }
}

int main(){
    int n;
    cin >> n;
    in.resize(n);
    pre.resize(n);
    for(int i = 0; i < n; i++){
        cin >> in[i];
        pos[in[i]] = i;
    }
    for(int i = 0; i < n; i++){cin >> pre[i];}
    Node* root = create(0, n-1, 0, n-1);
    bfs(root);
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    return 0;
}