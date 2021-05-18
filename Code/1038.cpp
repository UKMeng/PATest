#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string sa, string sb){
    int n = sa.size(), m = sb.size();
    for(int i = 0; i < max(n, m); i++){
        if(sa[i%n] != sb[i%m]) return sa[i%n] < sb[i%m];
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<string> input(n);
    for(int i = 0; i < n; i++){cin >> input[i];}
    sort(input.begin(), input.end(), cmp);
    string ans = "";
    int pos = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) ans += input[i];
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] != '0') {
            pos = i;
            flag = true;
            break;
        }
    }
    ans = ans.substr(pos, ans.size()-pos);
    if(flag) cout << ans << endl;
    else cout << 0 << endl; // 数字全为0的情况
    return 0;
}