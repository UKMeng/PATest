//AVL树模板
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int val;
};

Node* right_rotate(Node* tree){
    Node* temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}

Node* left_rotate(Node* tree){
    Node* temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;
}

Node* left_right_rotate(Node* tree){
    tree->left = left_rotate(tree->left);
    return right_rotate(tree);
}

Node* right_left_rotate(Node* tree){
    tree->right = right_rotate(tree->right);
    return left_rotate(tree);
}

int get_height(Node* tree){
    if(tree == nullptr) return 0;
    return max(get_height(tree->left), get_height(tree->right)) + 1;
}

Node* insert(Node* tree, int val){
    if(tree == nullptr){
        tree = new Node();
        tree->val = val;
    } else if(tree->val > val){
        tree->left = insert(tree->left, val);
        int l = get_height(tree->left), r = get_height(tree->right);
        if(l - r >= 2){
            if(val < tree->left->val){
                tree = right_rotate(tree);
            } else{
                tree = left_right_rotate(tree);
            }
        }
    } else{
        tree->right = insert(tree->right, val);
        int l = get_height(tree->left), r = get_height(tree->right);
        if(r - l >= 2){
            if(val < tree->right->val){
                tree = right_left_rotate(tree);
            } else{
                tree = left_rotate(tree);
            }
        }
    }
    return tree;
}

void level_order(Node* root){
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        ans.push_back(t->val);
        if(t->left != nullptr) {
            q.push(t->left);
        }
        if(t->right != nullptr) {
            q.push(t->right);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    Node* tree = nullptr;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        tree = insert(tree, temp);
    }
    level_order(tree);
    return 0;
}

/* 
input:
8
88 70 61 96 120 90 65 68
output:
88 65 96 61 70 90 120 68
*/