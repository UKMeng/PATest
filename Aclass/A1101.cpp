#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, max = 0;
    scanf("%d", &n);
    vector<int> a(n), temp, ans;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    temp = a;
    sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++) {
        if(a[i] == temp[i] && a[i] > max) { 
            ans.push_back(temp[i]);
            max = a[i];
        } else if(a[i] > max) {
            max = a[i];
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;      // 不加这个有一处格式错误
    return 0;
}