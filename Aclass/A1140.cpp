#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n;
    string ans;
    cin >> ans >> n;
    for(int i = 2; i <= n; i++) {
        int cnt = 0;
        char now = ans[0];
        string temp;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == now) cnt++;
            else {
                temp.push_back(now);
                temp.push_back('0' + cnt);
                cnt = 1;
                now = ans[i];
            }
        }
        temp.push_back(now);
        temp.push_back('0' + cnt);
        ans = temp;
    }
    cout << ans;
    return 0;
}