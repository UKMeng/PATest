#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isVaild(vector<int> a) {
    for(int i = 0; i < a.size() - 1; i++) {
        for(int j = i + 1; j < a.size(); j++) {
            if(a[i] - a[j] == 0 || abs(a[i] - a[j]) == j - i) return false;
        }
    }
    return true;
}
int main() {
    int k;
    cin >> k;
    while(k) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(isVaild(a)) cout << "YES" << endl;
        else cout << "NO" << endl;
        k--;
    }
    return 0;
}