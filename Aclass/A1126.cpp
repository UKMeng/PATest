// #include <iostream>
// using namespace std;
// int ans[510];
// int main() {
//     int n, m;
//     cin >> n >> m;
//     for(int i = 0; i < m; i++) {
//         int t1, t2;
//         cin >> t1 >> t2;
//         ans[t1] ++;
//         ans[t2] ++;
//     }
//     int flag = 0;
//     for(int i = 1; i <= n; i++) {
//         if(ans[i] % 2 != 0) flag++;
//         if(i != 1) cout << " ";
//         cout << ans[i];
//     } 
//     cout << endl;
//     if(flag == 0) cout << "Eulerian";
//     else if(flag == 2) cout << "Semi-Eulerian";
//     else cout << "Non-Eulerian";
//     return 0;
// }  错误 无法判断其连通性
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > v;
vector<bool> visit;
int cnt = 0;
void dfs(int index) {
    visit[index] = true;
    cnt++;
    for(int i = 0; i < v[index].size(); i++) {
        if(visit[v[index][i]] == false)
            dfs(v[index][i]);
    }
}
int main() {
    int n, m, a, b, even = 0;
    scanf("%d%d", &n, &m);
    v.resize(n + 1);
    visit.resize(n + 1);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(i != 1) printf(" ");
        printf("%d", v[i].size());
        if(v[i].size() % 2 == 0) even++;
    }
    printf("\n");
    dfs(1);
    if(even == n && cnt == n) printf("Eulerian");
    else if(even == n - 2 && cnt == n) 
        printf("Semi-Eulerian");
    else 
        printf("Non-Eulerian");
    return 0;
}