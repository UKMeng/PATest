#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s, f, b;
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len / 2; i++) f.push_back(s[i]);
        for(int i = len / 2; i < len; i++) b.push_back(s[i]);
        int t1 = stoi(s), t2 = stoi(f), t3 = stoi(b);
        if(t2 == 0 || t3 == 0) {cout << "No" << endl; continue;}
        if(t1 % (t2 * t3) == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}