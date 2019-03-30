#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int hashtable[maxn] = {-1};
bool h1[maxn];
vector<int> ans, temp;
int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        hashtable[c1] = c2, hashtable[c2] = c1;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        temp.push_back(t);
        h1[t] = true;
    }
    for(int i = 0; i < m; i++) {
        if(hashtable[temp[i]] == -1) ans.push_back(temp[i]);
        else {
            if(h1[hashtable[temp[i]]] == false) ans.push_back(temp[i]);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%lu\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) printf(" ");
        printf("%05d", ans[i]);
    }
    return 0;
}