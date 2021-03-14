#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

const int maxn = 10000;
bool isRed[maxn];
int pre[maxn];
unordered_set<int> cntBlack;

Node* create_tree(int preL, int preR){
    if(preL>preR) return nullptr;
    Node *root = new Node;
    root->data = pre[preL];
    int k;
    for(k=preL+1;k<=preR;++k){
        if(pre[k]>root->data) break;
    }
    root->left = create_tree(preL+1,k-1);
    root->right = create_tree(k,preR);
    return root;
}

void DFS(Node *root,int count_black,bool &flag){
    if(root == nullptr){
        cntBlack.insert(count_black);
        if(cntBlack.size() != 1){
            flag = false;
        }
        return;
    }
    if(!isRed[root->data]){
        ++count_black;
    } else{
        if((root->left!=nullptr&&isRed[root->left->data])||(root->right!=nullptr&&isRed[root->right->data])){
            flag = false;
            return;
        }
    }
    DFS(root->left, count_black, flag);
    DFS(root->right, count_black, flag);
}

int main(){
    int K, N;
    scanf("%d",&K);
    for(int i = 0; i < K; ++i){
        memset(isRed,0,sizeof(isRed));
        cntBlack.clear();
        scanf("%d",&N);
        bool isRedBlackTree = true;
        for(int j = 0; j < N; ++j){
            scanf("%d",&pre[j]);
            if(pre[j] < 0){
                pre[j] = -pre[j];
                isRed[pre[j]] = true;
            }
        }
        if(isRed[pre[0]]){
            isRedBlackTree = false;
            printf("No\n");
        } else{
            Node *root = create_tree(0, N-1);
            DFS(root,0,isRedBlackTree);
            if(isRedBlackTree){
                printf("Yes\n");
            }else{
                printf("No\n");
            }            
        }
    }
    return 0;
}