#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool isPalin(string s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    if(s == temp) return true;
    else return false;
}
int main() {
    string n;
    int k, cnt;
    cin >> n >> k;
    for(cnt = 0; cnt < k ; cnt++) {
        if(isPalin(n)) break;
        int len = n.length(), f = 0;
        string temp = n;
        reverse(temp.begin(), temp.end());
        for(int i = len - 1; i >= 0; i--) {
            int t = (n[i] - '0') + (temp[i] - '0') + f;
            f = 0;
            if(t >= 10) {
                f = 1;
                t = t - 10;
            }
            n[i] = '0' + t;
        }
        if(f) n.insert(n.begin(), '1');
    }
    cout << n << endl;
    cout << cnt;
    return 0;
}