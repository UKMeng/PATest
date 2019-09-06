#include <iostream>  // 贪心
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    double price, dis;
} ;
bool cmp(node a, node b) {return a.dis < b.dis;}
int main() {
    int cmax, cosume, n, nowid = 0;
    double d, dmax, cost = 0.0, remain = 0.0;
    cin >> cmax >> d >> cosume >>  n;
    dmax = cosume * cmax * 1.0;
    vector<node> gas(n + 1);
    for(int i = 0; i < n; i++) cin >> gas[i].price >> gas[i].dis;
    gas[n].dis = d;
    sort(gas.begin(), gas.end(), cmp);
    while(nowid != n) {
        int flag = 0, flag2 = 0;
        double minPrice = 999.9;
        for(int i = nowid + 1; i <= n; i++) {
            if(gas[i].dis - gas[nowid].dis > dmax) break;
            if(gas[i].price <= minPrice) {
                minPrice = gas[i].price;
                flag = i;
            }
            if(gas[i].price <= gas[nowid].price) {
                flag = i;
                flag2 = 1;
                break;
            }
        }
        if(flag == 0) {
            double ans = gas[nowid].dis + dmax;
            printf("The maximum travel distance = %.2f\n", ans);
            return 0;
        } else {
            if(flag2 == 1) {
                cost += (((gas[flag].dis - gas[nowid].dis) * 1.0 / cosume) - remain) * gas[nowid].price;
                remain = 0.0;
            } else {
                cost += (cmax - remain) * gas[nowid].price;
                remain = cmax - ((gas[flag].dis - gas[nowid].dis) * 1.0 / cosume);
            }
            cout << nowid << " " << cost << " " << remain << endl;
            nowid = flag;
        }
    }
    printf("%.2f", cost);
    return 0;
}