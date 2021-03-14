#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int l, r;
    string data;
} ;
vector<node> input;
string dfs(int index) {
    if(input[index].r == -1) return "(" + input[index].data + ")";
    else if(input[index].l == -1 && input[index].r != -1) {
        return "(" + input[index].data + dfs(input[index].r) + ")";
    } else {
        return "(" + dfs(input[index].l) + dfs(input[index].r) + input[index].data + ")";
    }
}
int main() {
    int n, head;
    cin >> n;
    input.resize(n);
    int hashtable[30] = {0};
    for(int i = 1; i <= n; i++) {
        cin >> input[i].data >> input[i].l >> input[i].r;
        if(input[i].l != -1) hashtable[input[i].l]++;
        if(input[i].r != -1) hashtable[input[i].r]++;
    } 
    for(int i = 1; i <= n; i++) {
        if(hashtable[i] == 0) {head = i; break;}
    }
    string ans;
    ans = dfs(head);
    cout << ans << endl;
    return 0;
}