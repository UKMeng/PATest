#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node{
    int val, ad, next;
};

int main(){
    // input
    int start;
    int num_node, k;
    scanf("%d%d%d", &start, &num_node, &k);
    vector<Node> v;
    Node temp[100010];
    for(int i = 0; i < num_node; i++){
        int tad, tnext, tval;
        scanf("%d%d%d", &tad, &tval, &tnext);
        Node t;
        t.ad = tad;
        t.next = tnext;
        t.val = tval;
        temp[tad] = t;
    }
    for(;start!=-1;start=temp[start].next) v.push_back(temp[start]);
    // 按要求整理
    vector<Node> ans;
    for(Node t: v) {if(t.val < 0) ans.push_back(t);}
    for(Node t: v) {if(t.val >= 0 && t.val <= k) ans.push_back(t);}
    for(Node t: v) {if(t.val > k) ans.push_back(t);}

    // output
    for(int i = 0; i < ans.size()-1; i++){
        printf("%05d %d %05d\n", ans[i].ad, ans[i].val, ans[i+1].ad);
    }
    printf("%05d %d -1\n", ans[ans.size()-1].ad, ans[ans.size()-1].val);
    return 0;
}