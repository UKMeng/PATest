#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct CUS{
    int arrT, proT;
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<CUS> customers;
    for(int i = 0; i < n; i++){
        int hh, mm, ss, p;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &p);
        CUS temp;
        int sum = hh * 3600 + mm * 60 + ss;
        if(sum > 61200) continue;
        temp.arrT = sum;
        temp.proT = p * 60;
        customers.push_back(temp);
    }
    sort(customers.begin(), customers.end(), [](CUS a, CUS b){return a.arrT < b.arrT;});
    // for(int i = 0; i < n; i++) cout << customers[i].arrT << endl;
    vector<int> waitTime(k, 28800);
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        // cout << customers[i].arrT << " " << ans << " " << customers[i].proT << endl;
        cnt++;
        if(customers[i].arrT < 28800) {
            ans += 28800 - customers[i].arrT;
            customers[i].arrT = 28800;
        }
        int minK = 0;
        int minWaitTime = 0x3f3f3f3f;
        for(int j = 0; j < k; j++){
            if(waitTime[j] < minWaitTime){
                minWaitTime = waitTime[j];
                minK = j;
            }
        }
        if(minWaitTime > 61200) {
            cnt--;
            break;
        }
        minWaitTime = minWaitTime - customers[i].arrT;
        if(minWaitTime <= 0) minWaitTime = 0;
        ans += minWaitTime;
        waitTime[minK] = waitTime[minK] + customers[i].proT;
    }
    if(cnt == 0) cout << 0.0 << endl;
    else printf("%.1f", (ans * 1.0) / (60 * cnt));
    return 0;
}