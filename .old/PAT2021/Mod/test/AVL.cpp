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
            if(tree->left->val > val){
                tree = right_rotate(tree);
            } else{
                tree = left_right_rotate(tree);
            }
        }
    } else{
        tree->right = insert(tree->right, val);
        int l = get_height(tree->left), r = get_height(tree->right);
        if(r - l >= 2){
            if(tree->right->val > val){
                tree = right_left_rotate(tree);
            } else{
                tree = left_rotate(tree);
            }
        } 
    }
    return tree;
}


void level_order(Node* tree){
    queue<Node*> q;
    vector<int> output;
    q.push(tree);
    while(!q.empty()){
        Node* temp = q.front(); q.pop();
        output.push_back(temp->val);
        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);

    }
    for(int i = 0; i < output.size(); i++){
        if(i != 0) cout << " " << output[i];
        else cout << output[i];
    }
    cout << endl;
}

int main(){
    vector<int> nums = {88, 70, 61, 96, 120, 90, 65, 68};
    Node* tree = nullptr;
    for(int i = 0; i < 8; i++){
        int temp = nums[i];
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