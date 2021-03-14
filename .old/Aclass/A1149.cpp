// #include <iostream>      出现编译错误、运行超时、内存超限等未知原因的问题,应该尽量避免开大数组
// #include <vector>
// using namespace std;
// int hashtable[100000];
// int e[100000][100000];
// int main() {
//     int n, m, u, v;
//     scanf("%d %d", &n, &m);
//     for(int i = 0; i < n; i++) {
//         scanf("%d %d", &u, &v);
//         hashtable[u] = hashtable[v] = 1;
//         e[u][v] = e[v][u] = 1;
//     }
//     while(m--) {
//         int k, temp, flag = 1;
//         vector<int> ans;
//         scanf("%d", &k);
//         for(int i = 0; i < k; i++) {
//             scanf("%d", &temp);
//             if(hashtable[temp] == 1) ans.push_back(temp);
//         }
//         for(int i = 0; i < ans.size(); i++) {
//             if(flag == 0) break;
//             for(int j = i + 1; j < ans.size(); j++) {
//                 if(e[ans[i]][ans[j]] == 1) {
//                     flag = 0;
//                     break;
//                 }  
//             }
//         }
//         printf("%s\n", flag == 1 ? "Yes" : "No");
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n, k, t1, t2;
    map<int, vector<int> > m;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &t1, &t2);
        m[t1].push_back(t2);
        m[t2].push_back(t1);
    }
    while(k--) {
        int cnt, flag = 0, a[100000] = {0};
        scanf("%d", &cnt);
        vector<int> v(cnt);
        for(int i = 0; i < cnt; i++) {
            scanf("%d", &v[i]);
            a[v[i]] = 1;
        }
        for(int i = 0; i < v.size(); i++) {
            if(flag == 1) break;
            for(int j = 0; j < m[v[i]].size(); j++) {
                if(a[m[v[i]][j]] == 1) flag = 1;
                break;
            }
        }
        printf("%s\n", flag == 1? "No" : "Yes");
    }
    return 0;
}