#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int getheight(node* root) {
    if(root == NULL) return 0;
    else return max(getheight(root -> lchild), getheight(root -> rchild)) + 1;
}
node* R(node* root) {
    node* t = root -> lchild;
    root -> lchild = t -> rchild;
    t -> rchild = root;
    return t;
}
node* L(node* root) {
    node* t = root -> rchild;
    root -> rchild = t -> lchild;
    t -> lchild = root;
    return t;
}
node* insert(node* root, int data) {
    if(root == NULL) {
        root = new node;
        root -> data = data;
        root -> lchild = NULL;
        root -> rchild = NULL;
    } else if(root -> data > data) {
        root -> lchild = insert(root -> lchild, data);
        if(getheight(root -> lchild) - getheight(root -> rchild) == 2) {
            if(root -> lchild -> data > data) root = R(root);
            else {
                root -> lchild = L(root -> lchild);
                root = R(root);
            }
        }
    } else {
        root -> rchild = insert(root -> rchild, data);
        if(getheight(root -> rchild) - getheight(root -> lchild) == 2) {
            if(root -> rchild -> data < data) root = L(root);
            else {
                root -> rchild = R(root -> rchild);
                root = L(root);
            }
        }
    }
    return root;
}
int main() {
    int n;
    cin >> n;
    node* root = NULL;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        root = insert(root, temp);
    }
    cout << root -> data;
    return 0;
}