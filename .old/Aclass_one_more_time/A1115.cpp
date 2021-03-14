#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
int lowest_level = 0;
struct node{
    node *left, *right;
    int val;
};

node * build(node * p, int v, int level){
    if(p == NULL){
        p = new node();
        p -> val = v;
        p -> right = NULL;
        p -> left = NULL;
        ans[level] += 1;
        if(level > lowest_level) lowest_level = level;
    } else if(v <= p -> val) {
        p -> left = build(p -> left, v, level + 1);
    } else if(v > p -> val) {
        p -> right = build(p -> right, v, level + 1);
    }
    return p;
}

int main(){
    int n; 
    cin >> n;
    vector<int> num;
    num.resize(n);
    for(int i = 0; i < n; i++) cin >> num[i];
    ans.resize(n);
    node * root = NULL;
    for(int i = 0; i < n; i++) root = build(root, num[i], 0);
    printf("%d + %d = %d", ans[lowest_level], ans[lowest_level - 1], ans[lowest_level] + ans[lowest_level - 1]);
    return 0;
}