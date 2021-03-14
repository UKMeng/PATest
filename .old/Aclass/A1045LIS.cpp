#include <iostream> // 用map运行超时；
using namespace std;
int col[10010], dp[10010], hashtable[210], A[210];
int main() {
    int n, m, l, cnt = 0, cutnum = 0, ans = -1;
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        hashtable[temp]++;
        A[temp] = cnt++;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        int temp;
        cin >> temp;
        if(hashtable[temp] == 0) continue;
        col[cutnum++] = temp;
    }
    for(int i = 0; i < cutnum; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(A[col[i]] >= A[col[j]] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        if(ans < dp[i]) ans = dp[i];
    }
    cout << ans;
    return 0;
}