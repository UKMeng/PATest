#include <iostream>
using namespace std;
const int maxn = 10010;
int main() {
    int k, n[maxn], dp[maxn], max = -1, s, e, st, et;
    cin >> k >> n[0];
    dp[0] = n[0];
    if(dp[0] > max) {max = dp[0]; s = 0; e = 0;}
    for(int i = 1; i < k; i++) {
        cin >> n[i];
        if(dp[i - 1] < 0) {
            dp[i] = n[i];
            st = et = i;
        } else {dp[i] = n[i] + dp[i - 1]; et = i;}
        if(dp[i] > max) {
            max = dp[i];
            s = st;
            e = et;
        }
    }
    if(max < 0) cout << "0 " << n[0] << " " << n[k - 1];
    else cout << max << " " << n[s] << " " << n[e];
    return 0;
}