#include <iostream> // 字符串
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool cmp(string a, string b) {
    return a + b < b + a;
}
int main() {
    int n;
    cin >> n;
    vector<string> str(n);
    string ans;
    for(int i = 0; i < n; i++) cin >> str[i];
    sort(str.begin(), str.end(), cmp);
    for(int i = 0; i < n; i++) ans += str[i];
    while(ans[0] == '0') ans.erase(ans.begin());
    if(ans.size() == 0) cout << "0" << endl;
    else cout << ans << endl;
    return 0;
}