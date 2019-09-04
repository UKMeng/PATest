// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int maxn = 1010;
// vector<int> hoppy[maxn], ans;
// int n, maxhoid = -1, father[maxn], cnt = 0, isRoot[maxn];
// void init() {
//     for(int i = 1; i <= n; i++) father[i] = i;
// }
// int findFather(int a) {
//     while(a != father[a]) a = father[a];
//     return a;
// }
// void Union(int a, int b) {
//     int faa = findFather(a), fab = findFather(b);
//     if(faa != fab) father[faa] = fab;
// }
// bool cmp(int a, int b) {return a > b;}
// int main() {
//     scanf("%d", &n);
//     init();
//     for(int i = 1; i <= n; i++) {
//         int honum;
//         scanf("%d:", &honum);
//         for(int j = 0; j < honum; j++) {
//             int hoid;
//             scanf("%d", &hoid);
//             if(hoid > maxhoid) maxhoid = hoid;
//             hoppy[hoid].push_back(i);
//         }
//     }
//     for(int i = 1; i <= maxhoid; i++) {
//         if(hoppy[i].size() != 0) {
//             for(int j = 1; j < hoppy[i].size(); j++) {
//                 Union(hoppy[i][j-1], hoppy[i][j]);
//             }
//         }
//     }
//     for(int i = 1; i <= n; i++) isRoot[findFather(i)]++;
//     for(int i = 1; i <= n; i++) {
//         if(isRoot[i] > 0) {
//             ans.push_back(isRoot[i]);
//             cnt++;
//         }
//     }
//     sort(ans.begin(), ans.end(), cmp);
//     cout << cnt << endl;
//     int cnt1 = 0;
//     for(int i = 0; i < ans.size(); i++) {
//         cout << ans[cnt1++];
//         if(cnt1 < cnt) cout << " ";
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> hoppy[1010];
int father[1010], ans[1010];
bool isVisit[1010];
int find(int x) {
    while(father[x] != x) x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA != faB) father[faA] = faB;
}
bool cmp(int a, int b) {return a > b;}
int main() {
    int n, maxhid = 0;
    cin >> n;
    for(int i = 0; i < n; i++) father[i] = i;
    for(int i = 0; i < n; i++) {
        int hnum;
        scanf("%d: ", &hnum);
        for(int j = 0; j < hnum; j++) {
            int hid;
            scanf("%d", &hid);
            hoppy[hid].push_back(i);
            if(hid > maxhid) maxhid = hid;
        }
    }
    for(int i = 1; i <= maxhid; i++) {
        if(hoppy[i].size() != 0 ) {
            for(int j = 1; j < hoppy[i].size(); j++) {
                Union(hoppy[i][j - 1], hoppy[i][j]);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int temp = find(i);
        if(isVisit[temp] == false) {
            cnt++;
            isVisit[temp] = true;
        }
        ans[temp]++;
    }
    sort(ans, ans + n, cmp);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}