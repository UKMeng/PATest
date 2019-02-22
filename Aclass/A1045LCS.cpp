#include <iostream> // LCS
#include <algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int A[maxc], B[maxn], dp[maxc][maxn];
int main() {
    int n, m, l;
    cin >> n;
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> A[i];
    cin >> l;
    for(int i = 1; i <= l; i++) cin >> B[i];
    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int i = 0; i <= l; i++) dp[0][i] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= l; j++) {
            int MAX = max(dp[i - 1][j], dp[i][j - 1]);
            if(A[i] == B[j]) dp[i][j] = MAX + 1;
            else dp[i][j] = MAX;
        }
    }
    cout << dp[m][l];
    return 0;
}