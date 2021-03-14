#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> seg(n);
    for(int i = 0; i < n; i++) {
        cin >> seg[i];
    }
    sort(seg.begin(), seg.end());
    int temp = seg[0];
    for(int i = 1; i < n; i++) {
        temp = (temp + seg[i]) / 2;
    }
    cout << temp;
    return 0;
}