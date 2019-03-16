#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> num;
int main() {
    int n, sum1 = 0, sum2 = 0;
    scanf("%d", &n);
    num.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    sort(num.begin(), num.end());
    if(n % 2 == 0) cout << 0 << " ";
    else cout << 1 << " ";
    for(int i = 0; i < n / 2; i++) sum1 += num[i];
    for(int i = n / 2; i < n; i++) sum2 += num[i];
    cout << sum2 - sum1 << endl;
    return 0;
}