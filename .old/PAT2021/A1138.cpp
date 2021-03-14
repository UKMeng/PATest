#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int val;
};

vector<int> pre, in;
unordered_map<int, int> pos;

Node* create_tree(int preL, int preR, int inL, int inR){
    if(preL > preR) return nullptr;
    Node* root = new Node();
    root->val = pre[preL];
    int p = pos[root->val];
    int ll = p - inL;
    root->left = create_tree(preL+1, preL+ll, inL, p-1);
    root->right = create_tree(preL+ll+1, preR, p+1, inR);
    return root;
}

vector<int> ans;
void post(Node* root){
    if(root->left==nullptr && root->right==nullptr){
        ans.push_back(root->val);
        return;
    }
    if(root->left!=nullptr) post(root->left);
    if(root->right!=nullptr) post(root->right);
    ans.push_back(root->val);
    return;
}

int main(){
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) {cin >> pre[i];}
    for(int i = 0; i < n; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }
    Node* root = create_tree(0, n-1, 0, n-1);
    post(root);
    cout << ans[0];
    return 0;
}