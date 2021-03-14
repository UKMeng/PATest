#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 首先构建AVL树，然后对AVL进行层序遍历，并在遍历的过程中判断这棵树是否为完全二叉树
struct Node{
    Node* left;
    Node* right;
    int val;
};

// create an AVL tree
Node* left_rotate(Node* tree){
    Node* temp = tree -> right;
    tree -> right = temp ->left;
    temp -> left = tree;
    return temp;
}

Node* right_rotate(Node* tree){
    Node* temp = tree -> left;
    tree -> left = temp -> right;
    temp -> right = tree;
    return temp;
}

Node* right_left_rotate(Node* tree){
    tree->right = right_rotate(tree->right);
    return left_rotate(tree);
}

Node* left_right_rotate(Node* tree){
    tree->left = left_rotate(tree->left);
    return right_rotate(tree);
}

int get_height(Node* tree){
    if(tree == nullptr) return 0;
    int l = get_height(tree->left);
    int r = get_height(tree->right);
    return max(l, r) + 1;
}

Node* insert(Node *tree, int val){
    if(tree == nullptr) {
        tree = new Node();
        tree->val = val;
    } else if(tree->val > val){
        tree->left = insert(tree->left, val);
        int l = get_height(tree->left), r= get_height(tree->right);
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
            if(val > tree->right->val){
                tree = left_rotate(tree);
            } else{
                tree = right_left_rotate(tree);
            }
        }
    }
    return tree;
}



// level-order traverse and judge
int is_complete = 1, after = 0;
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
            if(after) is_complete = 0;
        } else{
            after = 1;
        }
        if(t->right != nullptr) {
            q.push(t->right);
            if(after) is_complete = 0;
        } else{
            after = 1;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << " " << ans[i];
        else cout << ans[i];
    }
    cout << endl;
}

int main(){
    // input
    int n;
    cin >> n;

    // create an AVL tree
    Node* root = nullptr;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        root = insert(root, temp);
    }

    // level-order traverse
    level_order(root);

    // judge is a completed tree
    if(is_complete) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}