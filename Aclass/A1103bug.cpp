#include <iostream> // 各种错误
#include <algorithm>
#include <cmath>
using namespace std;
struct node {
    int factor[410], fsum = 0;
}ans[100010];
int n, k, p, num_so = 0;
bool cmp(node a, node b) {
    if(a.fsum != b.fsum) return a.fsum > b.fsum;
    else {
        for(int i = 0; i < k; i++) {
            if(a.factor[i] != b.factor[i]) return a.factor[i] > b.factor[i];
        }
    }
}
bool dfs(int n, int la, int sum) {
    for(int i = n; i >= 1; i--) {
        int temp = pow(i, p), tempSum = sum;
        if(la != k) {
            if(temp >= tempSum) continue;
            else {
                // cout << i << endl;
                ans[num_so].factor[la-1] = i;
                bool f = dfs(i, la + 1, tempSum - temp);  
                if(la <= k-2) continue;
                else {
                    if(f) return true;
                    else continue;
                }
            }
        }
        else if(la == k) {
            if(temp == tempSum) {
                // cout << i << endl;
                ans[num_so++].factor[la-1] = i;
                return true;
            }
            else continue;
        }
    }
    return false;
}
int main() {
    cin >> n >> k >> p;
    dfs(n, 1, n);
    // cout << num_so << endl;
    if(num_so == 0) cout << "Impossible";
    else {
        for(int i = 0; i < num_so; i++) {
            for(int j = 0; j < k; j++) {
                ans[i].fsum += ans[i].factor[j];
            }
        }
        cout << n << " = ";
        sort(ans, ans + num_so, cmp);
        // for(int j = 0; j < num_so; j++)
        // {   cout << ans[j].fsum << endl;
        for(int i = 0; i < k; i++) {
            if(i != 0) cout << " + ";
            cout << ans[0].factor[i] << "^" << p;
        }
        //cout << endl;}
    }
    return 0;
}