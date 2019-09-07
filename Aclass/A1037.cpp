#include <iostream> // 贪心
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(long long a, long long b) {return a > b;}
int main() {
    int n, m;
    long long ans = 0;
    scanf("%d", &n);
    vector<long long> coupon(n);
    for(int i = 0; i < n; i++) scanf("%lld", &coupon[i]);
    sort(coupon.begin(), coupon.end(), cmp);
    scanf("%d", &m);
    vector<long long> product(m);
    for(int i = 0; i < m; i++) scanf("%lld", &product[i]);
    sort(product.begin(), product.end(), cmp);
    for(int i = 0; i < min(n, m); i++) {
        if(coupon[i] <= 0 || product[i] <= 0) break;
        ans += coupon[i] * product[i];
    }
    reverse(coupon.begin(), coupon.end());
    reverse(product.begin(), product.end());
    for(int i = 0; i < min(n, m); i++) {
        if(coupon[i] >= 0 || product[i] >= 0) break;
        ans += coupon[i] * product[i];
    }
    printf("%lld", ans);
    return 0;
}