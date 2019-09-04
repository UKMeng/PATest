// #include <iostream> // AVL complete tree
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// using namespace std;
// struct node {
//     int v;
//     node * left, * right;
// } ;
// node * newnode(int v) {
//     node * root = new node();
//     root -> left = NULL;
//     root -> right = NULL;
//     root -> v = v;
//     return root;
// }
// int getHeight(node * root) {
//     if(root == NULL) return 0;
//     int l = getHeight(root -> left);
//     int r = getHeight(root -> right);
//     return max(l, r) + 1;
// }
// int getBF(node * root) {
//     return getHeight(root -> left) - getHeight(root -> right);
// }
// node * leftRotation(node * root) {
//     node * temp = root -> right;
//     root -> right = temp -> left;
//     temp -> left = root;
//     return temp;
// }
// node * rightRotation(node * root) {
//     node * temp = root -> left;
//     root -> left = temp -> right;
//     temp -> right = root;
//     return temp;
// }
// node * insert(node * root, int v) {
//     if(root == NULL) {
//         root = newnode(v);
//         return root;
//     } else if(root -> v > v) {
//         root -> left = insert(root -> left, v);
//         if(getBF(root) == 2) {
//             if(getBF(root -> left) == 1) {
//                 root = rightRotation(root);
//             } else if(getBF(root -> left) == -1) {
//                 root -> left = leftRotation(root -> left);
//                 root = rightRotation(root);
//             }
//         }
//     } else {
//         root -> right = insert(root -> right, v);
//         if(getBF(root) == -2) {
//             if(getBF(root -> right) == -1) {
//                 root = leftRotation(root);
//             } else if(getBF(root -> right) == 1) {
//                 root -> right = rightRotation(root -> right);
//                 root = leftRotation(root);
//             }
//         }
//     }
//     return root;
// }
// int isComplete = 1, after = 0;
// vector<int> levelOrder(node * root) {      // 层序遍历以及检查Complete（不会）
//     vector<int> v;
//     queue<node *> queue;        // 对于二叉树的完整性，一旦出现空节点（NULL)，之后将不允许再出现其他节点
//     queue.push(root);
//     while(!queue.empty()) {
//         node *temp = queue.front();
//         queue.pop();
//         v.push_back(temp -> v);
//         if(temp -> left != NULL) {
//             if(after) isComplete = 0;
//             queue.push(temp -> left);
//         } else {
//             after = 1;
//         }
//         if(temp -> right != NULL) {
//             if(after) isComplete = 0;
//             queue.push(temp -> right);
//         } else {
//             after = 1;
//         }
//     }
//     return v;
// }
// int main() {
//     int n;
//     cin >> n;
//     node * root = NULL;
//     for(int i = 0; i < n; i++) {
//         int temp;
//         cin >> temp;
//         root = insert(root, temp);
//     }
//     vector<int> ans = levelOrder(root);
//     for(int i = 0; i < n; i++) {
//         if(i != 0) cout << " ";
//         cout << ans[i];
//     }
//     cout << endl;
//     if(isComplete) cout << "YES"; else cout << "NO";
//     return 0;
// }
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node * leftRotate(node *tree) {
    node *temp = tree -> right;
    tree -> right = temp -> left;
    temp -> left = tree;
    return temp;
}
node * rightRotate(node *tree) {
    node *temp = tree -> left;
    tree -> left = temp -> right;
    temp -> right = tree;
    return temp;
}
node * rightleftRotate(node * tree) {
    tree -> right = rightRotate(tree -> right);
    return leftRotate(tree);
}
node * leftrightRotate(node * tree) {
    tree -> left = leftRotate(tree -> left);
    return rightRotate(tree);
}
int getHeight(node *tree) {
    if(tree == NULL) return 0;
    int l = getHeight(tree -> left);
    int r = getHeight(tree -> right);
    return max(l, r) + 1;
}
node * insert(node *tree, int val) {
    if(tree == NULL) {
        tree = new node();
        tree -> val = val;
    } else if(tree -> val > val) {
        tree -> left = insert(tree -> left, val);
        int l = getHeight(tree -> left), r = getHeight(tree -> right);
        if(l - r >= 2) {
            if(val < tree -> left -> val) {
                tree = rightRotate(tree);
            } else tree = leftrightRotate(tree);
        }
    } else {
        tree -> right = insert(tree -> right, val);
        int l = getHeight(tree -> left), r = getHeight(tree -> right);
        if(r - l >= 2) {
            if(val < tree -> right -> val) {
                tree = leftRotate(tree);
            } else tree = rightleftRotate(tree);
        }
    }
    return tree;
}
int isComplete = 1, after = 0;
vector<int> levelOrder(node * tree) {
    vector<int> v;
    queue<node *> queue;
    queue.push(tree);
    while(!queue.empty()) {
        node * temp = queue.front();
        queue.pop();
        v.push_back(temp -> val);
        if(temp -> left != NULL) {
            if(after) isComplete = 0;
            queue.push(temp->left);
        } else {after = 1;}
        if(temp -> right != NULL) {
            if(after) isComplete = 0;
            queue.push(temp -> right);
        } else {after = 1;}
    }
    return v;
}
int main() {
    int n, temp;
    scanf("%d", &n);
    node *tree = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        tree = insert(tree, temp);
    }
    vector<int> v = levelOrder(tree);
    for(int i = 0; i < v.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n%s", isComplete ? "YES" : "NO");
    return 0;
}