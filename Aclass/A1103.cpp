#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> v, ans, tempAns;
int n, k, p, maxSum = -1;
void init() {
    int temp = 0, index = 1;
    while(temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
void dfs(int index, int la, int sum, int inSum) {
    if(la == k) {
        if(sum == n && inSum > maxSum) {
            ans = tempAns;
            maxSum = inSum;
        }
        return;
    }
    while(index >= 1) {
        if(sum + v[index] <= n) {
            tempAns[la] = index;
            dfs(index, la + 1, sum + v[index], inSum + index);
        }
        if(index == 1) return;
        index--;
    }
}
int main() {
    cin >> n >> k >> p;
    tempAns.resize(k);
    init();
    dfs(v.size() - 1, 0, 0, 0);
    if(maxSum == -1) cout << "Impossible";
    else {
        cout << n << " = ";
        for(int i = 0; i < k; i++) {
            if(i != 0) cout << " + ";
            cout << ans[i] << "^" << p;
        }
    }
    return 0;
}