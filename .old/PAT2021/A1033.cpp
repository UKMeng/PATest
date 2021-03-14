#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 如果在能前进范围内有比目前的加油站便宜的加油站，加到能前进到该加油站的油
// 如果没有，但是在前进范围内能够到达终点，加到能前进到终点的油
// 如果没有，在前进范围内找到的最便宜的加油站，加满油
// 如果没有能到的加油站，也不能到终点，打印最大行驶距离为当前行驶距离加上最大能前进距离

struct node{
    double price, dis;
};

bool cmp(node a, node b) {return a.dis < b.dis;}

int main(){
    int cmax, cosume, n, nowid = 0;
    double d, dmax, cost = 0.0, remain = 0.0;
    cin >> cmax >> d >> cosume >> n;
    dmax = cosume * cmax * 1.0;
    vector<node> gas(n+1);
    for(int i = 0; i < n; i++) cin >> gas[i].price >> gas[i].dis;
    gas[n].dis = d;
    sort(gas.begin(), gas.end(), cmp);
    if(gas[0].dis != 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    while(nowid != n){
        int flag = 0, flag2 = 0;
        double minPrice = 999.9;
        for(int i = nowid + 1; i <= n; i++){
            if(gas[i].dis - gas[nowid].dis > dmax) break;
            if(gas[i].price <= minPrice){
                minPrice = gas[i].price;
                flag = i;
            }
            if(gas[i].price <= gas[nowid].price){
                flag = i;
                flag2 = 1;
                break;
            }
        }
        if(flag == 0){
            double ans = gas[nowid].dis + dmax;
            printf("The maximum travel distance = %.2f\n", ans);
            return 0;
        } else{
            if(flag2 == 1){
                cost += (((gas[flag].dis - gas[nowid].dis) * 1.0 / cosume) - remain) * gas[nowid].price;
                remain = 0.0;
            } else{
                cost += (cmax - remain) * gas[nowid].price;
                remain = cmax - ((gas[flag].dis - gas[nowid].dis) * 1.0 / cosume);
            }
            nowid = flag;
        }
    }
    printf("%.2f", cost);
    return 0;
}