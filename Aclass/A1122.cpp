#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool G[210][210];
int main() {
    int n, m, cnt;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = true;
    }
    cin >> cnt;
    while(cnt--) {
        int k;
        cin >> k;
        vector<int> v(k);
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for(int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if(s.size() != n || k - 1 != n || v[0] != v[k-1]) flag1 = 0;
        for(int i = 0; i < k - 1; i++)
            if(G[v[i]][v[i+1]] == 0) flag2 = 0;
        printf("%s",flag1 && flag2 ? "YES\n" : "NO\n");
    }
    // int k;
    // cin >> k;
    // for(int i = 0; i < k; i++) {
    //     int q;
    //     cin >> q;
    //     if(q != n + 1) {
    //         cout << "NO" << endl;
    //         int temp;
    //         for(int j = 0; j < q; j++) cin >> temp;
    //     } else {
    //         int temp, first, last;
    //         bool flag = true;
    //         cin >> first;
    //         last = first;
    //         set<int> s;
    //         s.insert(first);
    //         for(int j = 0; j < n; j++) {
    //             cin >> temp;
    //             if(j == n - 1) {
    //                 if(temp != first) {
    //                     flag = false;
    //                     break;
    //                 }
    //             } else {
    //                 if(G[temp][last]) {
    //                     if(s.find(temp) != s.end()) {
    //                         flag = false;
    //                         break;
    //                     } else s.insert(temp);
    //                 } else {
    //                     flag = false;
    //                     break;
    //                 }
    //             }
    //             last = temp;
    //         }
    //         if(flag) cout << "YES" << endl;
    //         else cout << "NO" << endl;
    //     }
    // }
    return 0;
}