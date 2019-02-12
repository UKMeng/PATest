#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<int> s[60];
int main() {
    int n, m, cn;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            s[i].insert(temp);
        }
    }
    cin >> cn;
    for(int i = 0; i < cn; i++) {
        int c1, c2, nc = 0, nt, t;
        cin >> c1 >> c2;
        nt = s[c2 - 1].size();
        t = s[c1 - 1].size();
        for(auto it = s[c1 - 1].begin(); it != s[c1 - 1].end(); it++) {
            if(s[c2 - 1].find(*it) != s[c2 - 1].end()) nc++;
            else nt++;
        }
        double ans = nc * 100.0 / nt;
        printf("%.1f%%\n", ans);
    }
    return 0;
}