#include <iostream>
#include <vector>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int value;
};

void insert(Node* &root, int v){
    if(root == nullptr){
        root = new Node();
        root->value = v;
        return;
    }
    if(v < root->value){
        insert(root->left, v);
    } else{
        insert(root->right, v);
    }
}

void getPre(Node* root, vector<int> &pre, bool flag){
    if(root == nullptr) return;
    pre.push_back(root->value);
    if(flag){
        getPre(root->left, pre, flag);
        getPre(root->right, pre, flag);
    } else{
        getPre(root->right, pre, flag);
        getPre(root->left, pre, flag);
    }
}

void getPost(Node* root, vector<int> &post, bool flag){
    if(root == nullptr) return;   
    if(flag){
        getPost(root->left, post, flag);
        getPost(root->right, post, flag);
    } else{
        getPost(root->right, post, flag);
        getPost(root->left, post, flag);
    }
    post.push_back(root->value);
}

bool preCheck(Node* root, vector<int> input){
    vector<int> pre;
    getPre(root, pre, true);
    return pre == input;
}

bool preMirrorCheck(Node* root, vector<int> input){
    vector<int> pre;
    getPre(root, pre, false);
    return pre == input;
}

int main(){
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++) cin >> input[i];
    Node* root = new Node();
    root->value = input[0];
    for(int i = 1; i < n; i++){
        insert(root, input[i]);
    }
    if(preCheck(root, input)){
        cout << "YES" << endl;
        vector<int> post;
        getPost(root, post, true);
        for(int i = 0; i < n; i++){
            if(i != 0) cout << " " << post[i];
            else cout << post[i];
        }
    } else if(preMirrorCheck(root, input)){
        cout << "YES" << endl;
        vector<int> post;
        getPost(root, post, false);
        for(int i = 0; i < n; i++){
            if(i != 0) cout << " " << post[i];
            else cout << post[i];
        }
    } else{
        cout << "NO" << endl;
    }
    return 0;
}