#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10010;
int father[maxn], cnt[maxn];
bool exist[maxn];
int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}
void init() {
    for(int i = 0; i < maxn; i++) {
        father[i] = i;
    }
}
int main() {
    int n, m;
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        vector<int> temp;
        temp.resize(m);
        for(int i = 0; i < m; i++) {
            scanf("%d", &temp[i]);
            exist[temp[i]] = true;
            if(i > 0) {
                Union(temp[i - 1], temp[i]);
            }
        }
    }
    for(int i = 1; i < maxn; i++) {
        if(exist[i] == true) {
            int root = findFather(i);
            cnt[root]++;
        }
    }
    int ans = 0, max = 0;
    for(int i = 1; i < maxn; i++) {
        if(exist[i] == true && cnt[i] != 0) {
            ans++;
            max += cnt[i];
        }
    }
    cout << ans << " " << max << endl;
    int query;
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(findFather(a) == findFather(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}