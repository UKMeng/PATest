#include <iostream> 
#include <map>
#include <cstring>
using namespace std;
int main(){
    int n, p, t;
    bool ans[11];
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        map<char, int> m;
        for(int j = 0; j < s.size(); j++){
            m[s[j]]++;
            if(s[j] == 'P') p = j;
            if(s[j] == 'T') t = j;
        }
        if(m['P'] == 1 && m['T'] == 1 && m['A'] != 0 && m.size() == 3 && t - p != 1 && p * (t - p - 1) == s.length() - t - 1) ans[i] = true;
        else ans[i] = false;
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
// https://github.com/liuchuo/PAT/blob/master/BasicLevel_C%2B%2B/1003.%20%E6%88%91%E8%A6%81%E9%80%9A%E8%BF%87%EF%BC%81(20).cpp