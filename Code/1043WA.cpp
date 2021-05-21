#include <iostream>
#include <vector>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

void insert(Node* &root, int data, bool flag){
    if(root == nullptr){
        root = new Node();
        root->data = data;
        return;
    } else if(root->data > data){
        if(flag){
            insert(root->left, data, flag);
        } else{
            insert(root->right, data, flag);
        }
    } else if(root->data <= data){
        if(flag){
            insert(root->right, data, flag);
        }
        else{
            insert(root->left, data, flag);
        }
    }
}

Node* buildBST(vector<int> num, bool flag){
    int n = num.size();
    Node* root = new Node();
    root->data = num[0];
    for(int i = 1; i < n; i++){
        insert(root, num[i], flag);
    }
    return root;
}

vector<int> post;
void postT(Node* root){
    if(root == nullptr) return;
    postT(root->left);
    postT(root->right);
    post.push_back(root->data);
}

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) cin >> num[i];
    if(n == 1) {
        cout << "YES" << endl;
        cout << num[0];
    }
    bool flag1;
    if(num[1] < num[0]) flag1 = true; // flag1 true not-mirror
    else flag1 = false; // flag1 false mirror
    bool flag2 = true;
    bool flag3 = true;
    if(flag1){
        int pos1 = 1;
        for(int i = 1; i < n; i++){
            if(num[i] >= num[0]){
                pos1 = i + 1;
                break;
            }
        }
        for(int i = pos1; i < n; i++){
            if(num[i] < num[0]){
                flag2 = false;
                break;
            }
        }
    } else{
        int pos1 = 1;
        for(int i = 1; i < n; i++){
            if(num[i] < num[0]){
                pos1 = i + 1;
                break;
            }
        }
        for(int i = pos1; i < n; i++){
            if(num[i] >= num[0]){
                flag3 = false;
                break;
            }
        }
    }
    
    if(flag2 && flag3) {
        cout << "YES" << endl;
        // 建树
        Node* root = buildBST(num, flag1);
        // 得到后序遍历
        postT(root);
        for(int i = 0; i < n; i++) {
            if(i != 0) cout << " " << post[i];
            else cout << post[i];
        }
        cout << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}