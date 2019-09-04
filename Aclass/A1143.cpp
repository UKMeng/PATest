// #include <iostream>      存在问题， 无法对于全是同一个数的数找LCA
// #include <vector>
// using namespace std;
// struct node {
//     int l, r, anc;
// } tree[10010];
// void build(int temp, int root){
//     if(temp < root) {
//         if(tree[root].l == 0) {
//             tree[root].l = temp;
//             tree[temp].anc = root;
//             return;
//         } else build(temp, tree[root].l);
//     } else{
//         if(tree[root].r == 0) {
//             tree[root].r = temp;
//             tree[temp].anc = root;
//             return;
//         } else build(temp, tree[root].r);
//     }
// }
// int hashtable[10010];
// int main() {
//     int query, n, root;
//     cin >> query >> n >> root;
//     tree[root].anc = -1;
//     hashtable[root] = 1;
//     for(int i = 0; i < n - 1; i++) {
//         int temp;
//         cin >> temp;
//         hashtable[temp] = 1;
//         build(temp, root);
//     }
//     for(int i = 0; i < query; i++) {
//         int a, b, flag1 = 0, flag2 = 0;
//         cin >> a >> b;
//         if(hashtable[a] == 0) flag1 = 1;
//         if(hashtable[b] == 0) flag2 = 1;
//         if(flag1 == 1) {
//             if(flag2 == 1) {
//                 cout << "ERROR: " << a << " and " << b << " are not found." << endl;
//             } else cout << "ERROR: " << a << " is not found." << endl;
//             continue;
//         } else if(flag2 == 1) {
//             cout << "ERROR: " << b << " is not found." << endl;
//             continue;
//         }
//         int hashanc[10010] = {0};
//         int temp = a;
//         while(temp != -1) {
//             temp = tree[temp].anc;
//             hashanc[temp] = 1;
//         } temp = b;
//         if(hashanc[b] == 1) {
//             cout << b << " is an ancestor of " << a << "." << endl;
//             continue;
//         }
//         while(temp != -1) {
//             temp = tree[temp].anc;
//             if(temp == a) {
//                 cout << a << " is an ancestor of " << b << "." << endl;
//                 break;
//             } else if(hashanc[temp] == 1) {
//                 cout << "LCA of " << a << " and " << b << " is " << temp << "." << endl;
//                 break;
//             }
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, bool> mp;
int main() {
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        for(int j = 0; j < n; j++) {
            a = pre[j];
            if((a >= u && a <= v) || (a >= v && a <= u))   break; // LCA 算法
        }
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}