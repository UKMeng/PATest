// #include <iostream>         有两个检查点运行超时
// #include <vector>
// #include <algorithm>
// using namespace std;
// vector<int> ans;
// int times[50010];
// bool cmp(int a, int b) {
//     if(times[a] != times[b]) return times[a] > times[b];
//     else return a < b;
// }
// int main() {
//     int k, m, first;
//     // cin >> k >> m >> first;
//     scanf("%d%d%d", &k, &m, &first);
//     ans.push_back(first);
//     times[first]++;
//     for(int i = 0; i < k - 1; i++) {
//         int temp, pos;
//         scanf("%d", &temp);
//         printf("%d:", temp);
//         if(ans.size() < m) {
//             for(int j = 0; j < ans.size(); j++) printf(" %d", ans[j]);
//         } else for(int j = 0; j < m; j++) printf(" %d", ans[j]);
//         printf("\n");
//         if(times[temp] == 0) {
//             ans.push_back(temp);
//         }
//         times[temp]++;
//         sort(ans.begin(), ans.end(), cmp);     
//     }
//     return 0;
// }
#include <iostream>
#include <set>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    node(int a, int b): value(a), cnt(b){};
    bool operator < (const node & a) const {        // 重载 < 
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
} ;
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it -> value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node(num, book[num]));
        if (it != s.end()) s.erase(it);
        book[num]++;
        s.insert(node(num, book[num]));
    }
    return 0;
}