#include <iostream>
#include <vector>

using namespace std;

int getpost(int root, int tail, int last_root, vector<int> &pre, vector<int> &post){
    if(root > tail) return 0;
    int i = root;
    while(i < tail && pre[i + 1] < pre[root]){
        if(pre[i + 1] < last_root) return 0;
        i += 1;
    }
    if(i < tail && pre[i + 1] == pre[root]) i += 1;
    if(i < tail && pre[i + 1] < pre[root]) return 0;
    getpost(root + 1, i, -99999, pre, post);
    getpost(i + 1, tail, pre[root], pre, post);
    post.push_back(pre[root]);
}

int main() {
    int num_nodes;
    cin >> num_nodes;
    vector<int> pre(num_nodes);
    vector<int> post;
    for(int i = 0; i < num_nodes; i++){
        cin >> pre[i];
    }
    if(num_nodes == 1){
        cout << "YES" << endl;
        cout << pre[0] << endl;
        return 0;
    }
    if(pre[1] > pre[0]) {
        for(int i = 0; i < num_nodes; i++) pre[i] = -pre[i];
    }
    getpost(0, num_nodes - 1, -99999, pre, post);
    if(post.size() == num_nodes){
        cout << "YES" << endl;
        cout << abs(post[0]);
        for(int i = 1; i < num_nodes; i++) cout << " " << abs(post[i]);
    } else cout << "NO" << endl;
    return 0;
}