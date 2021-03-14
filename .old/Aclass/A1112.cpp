#include <iostream>
#include <cstring>
#include <cctype>
#include <set>
using namespace std;
set<char> ans;
bool vis[38], notb[38];
int getId(char c) {
    int ans;
    if(isalpha(c)) ans = c - 'a' + 10;
    else if(c == '_') ans = 36;
    else if(c == '#') ans = 37;
    else ans = c - '0';
    return ans;
}
int main() {
    int k, cnt = 1;
    cin >> k;
    string s;
    cin >> s;
    char temp = '#';
    s = s + '#';
    for(int i = 0; i < s.length(); i++) {
        int id = getId(temp), id2 = getId(s[i]);
        if(s[i] == temp) cnt++;
        else {
            if(cnt % k != 0) notb[id] = true; 
            cnt = 1;
        }
        if(i != s.length() - 1) vis[id2] = (cnt % k == 0);
        temp = s[i];
    }
    for(int i = 0; i < s.length(); i++) {
        int id = getId(s[i]);
        if(notb[id] == true) vis[id] = false;
    }
    for(int i = 0; i < s.length(); i++) {
        int id = getId(s[i]);
        if(vis[id] && ans.find(s[i]) == ans.end()) {
            cout << s[i];
            ans.insert(s[i]);
        }
    }
    cout << endl;
    for(int i = 0; i < s.length() - 1; i++) {
        int id = getId(s[i]);
        cout << s[i];
        if(vis[id]) i = i + k - 1;
    }
    return 0;
}