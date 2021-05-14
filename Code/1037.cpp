#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> coupon(n);
    for(int i = 0; i < n; i++) cin >> coupon[i];
    cin >> m;
    vector<int> product(m);
    for(int i = 0; i < m; i++) cin >> product[i];
    int ans = 0;
    sort(coupon.begin(), coupon.end());
    sort(product.begin(), product.end());
    int lc = 0, lp = 0;
    while(lc < n && lp < m && coupon[lc] < 0 && product[lp] < 0){
        ans += coupon[lc++] * product[lp++];
    }
    int rc = n-1, rp = m-1;
    while(rc >= 0 && rp >= 0 && coupon[rc] > 0 && product[rp] > 0){
        ans += coupon[rc--] * product[rp--];
    }
    cout << ans << endl;
    return 0;
}