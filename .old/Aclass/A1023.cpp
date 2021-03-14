#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool f2 = false;
int num[10], num2[10];
void dou(string &s) {
    bool f = false;
    if(s[0] - '0' >= 5) f2 = true;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++) {
        int temp = s[i] - '0';
        if(f) s[i] = '1';
        else s[i] = '0';
        if(temp < 5) {
            f = false;
            s[i] = '0' + (s[i] - '0') + (temp * 2);
        }
        else {
            f = true;
            s[i] = '0' + (s[i] - '0') + (temp * 2 - 10);
        }
    }
    reverse(s.begin(), s.end());
    if(f2) s.insert(s.begin(), '1');
}
int main() {
    string n;
    cin >> n;
    int len = n.length();
    for(int i = 0; i < len; i++) num[n[i] - '0']++;
    dou(n);
    if(f2) cout << "No" << endl;
    else {
        bool f3 = true;
        for(int i = 0; i < len; i++) num2[n[i] - '0']++;
        for(int i = 0; i < 10; i++) if(num[i] != num2[i]) {f3 = false; break;}
        if(f3) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    cout << n;
    return 0;
}