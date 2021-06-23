#include <iostream>
#include <vector>
using namespace std;
// AVL模板题


struct Node{
    Node* left;
    Node* right;
    int val;
};

Node* rightRotate(Node* tree){
    Node* temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}

Node* leftRotate(Node* tree){
    Node* temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;
}

Node* leftRightRotate(Node* tree){
    tree->left = leftRotate(tree->left);
    return rightRotate(tree);
}

Node* rightLeftRotate(Node* tree){
    tree->right = rightRotate(tree->right);
    return leftRotate(tree);
}

int getHeight(Node *tree){
    if(tree == nullptr) return 0;
    return max(getHeight(tree->left), getHeight(tree->right)) + 1;
}

Node* insert(Node* tree, int val){
    if(tree == nullptr){
        tree = new Node();
        tree->val = val;
    } else if(tree->val > val){
        tree->left = insert(tree->left, val);
        int l = getHeight(tree->left), r = getHeight(tree->right);
        if(l - r >= 2){
            if(val < tree->left->val){
                tree = rightRotate(tree);
            } else{
                tree = leftRightRotate(tree);
            }
        }
    } else{
        tree->right = insert(tree->right, val);
        int l = getHeight(tree->left),  r = getHeight(tree->right);
        if(r - l >= 2){
            if(val >= tree->right->val){
                tree = leftRotate(tree);
            } else{
                tree = rightLeftRotate(tree);
            }
        }
    }
    return tree;
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
    cout << tree->val << endl;
    return 0;
}