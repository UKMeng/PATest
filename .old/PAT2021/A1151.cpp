#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 有问题，最后两个测试点通不过
vector<int> in, pre;
unordered_map<int, int> pos;
unordered_map<int, int> node_id;
unordered_map<int, int> id_node;

void create_tree(int preL, int preR, int inL, int inR, int id){
    if(preL > preR) return;
    int data = pre[preL];
    int root_pos = pos[data];
    int left_len = root_pos - inL;
    create_tree(preL+1, preL+left_len, inL, root_pos-1, id*2);
    create_tree(preL+left_len+1, preR, root_pos+1, inR, id*2+1);
    node_id[data] = id;
    id_node[id] = data;
    return;
}

int main(){
    int k, n;
    cin >> k >> n;
    in.resize(n);
    pre.resize(n);
    for(int i = 0; i < n; i++){
        cin >> in[i];
        pos[in[i]] = i;
    }
    for(int i = 0; i < n; i++) {cin >> pre[i];}

    create_tree(0, n-1, 0, n-1, 1);

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        int flag1 = 0, flag2 = 0;
        if(node_id[a] != 0) flag1 = 1;
        if(node_id[b] != 0) flag2 = 1;
        if(flag1 == 1 && flag2 == 1){
            int t1 = node_id[a], t2 = node_id[b], id1 = node_id[a], id2 = node_id[b];
            while(t1 != t2){
                if(t1 > t2) t1 /= 2;
                else t2 /= 2;
            }
            if(t1 == id1) {
                printf("%d is an ancestor of %d.\n", a, b);
            } else if(t1 == id2){
                printf("%d is an ancestor of %d.\n", b, a);
            } else{
                printf("LCA of %d and %d is %d.\n", a, b, id_node[t1]);
            }
        } else if(flag1 == 0 && flag2 == 1){
            printf("ERROR: %d is not found.\n", a);
        } else if(flag2 == 0 && flag1 == 1){
            printf("ERROR: %d is not found.\n", b);
        } else if(flag1 == 0 && flag2 == 0){
            printf("ERROR: %d and %d are not found.\n", a, b);
        }
    }
    return 0;
}


