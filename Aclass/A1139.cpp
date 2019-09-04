#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10010;
const int INF = 0x7fffffff;
set<int> same_gender[maxn];
int G[maxn][maxn];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        char s1[6], s2[6];
        scanf("%s %s", s1, s2);         // 考虑同性恋以及-0000和0000的情况
        int id1 = stoi(s1), id2 = stoi(s2);
        if(strlen(s1) == strlen(s2)) {
            same_gender[abs(id1)].insert(abs(id2));
            same_gender[abs(id2)].insert(abs(id1));
        }
        G[abs(id1)][abs(id2)] = G[abs(id2)][abs(id1)] = INF;
    }
    int query;
    cin >> query;
    while(query--) {
        int id1, id2;
        int cnt = 0;
        scanf("%d %d", &id1, &id2);
        vector<int> ans;
        for(auto it = same_gender[abs(id1)].begin();it != same_gender[abs(id1)].end(); it++) {
            // cout << *it << ":";
            if(*it == abs(id2)) continue;
            for(auto it2 = same_gender[abs(id2)].begin(); it2 != same_gender[abs(id2)].end(); it2++) {
                // cout << *it2 << endl;
                if(*it2 == abs(id1)) continue;
                if(G[*it][*it2] != 0) {
                    // cout << *it << " " << *it2;
                    cnt++;
                    ans.push_back(*it);
                    ans.push_back(*it2);
                } 
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < 2 * cnt; i += 2) {
            printf("%04d %04d\n", ans[i], ans[i + 1]);
        }
    }
    return 0;
}