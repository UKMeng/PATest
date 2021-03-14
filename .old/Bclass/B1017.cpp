#include <iostream>
#include <cstring>
using namespace std;
int main() {
    string s;
    int d, temp = 0, t = 0, pos = 0;
    cin >> s >> d;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        if(temp + s[i] - '0' < d) {
            temp += 10 * (s[i] - '0'); 
            if(pos != 0) {cout << '0'; pos++;}
        }
        else {
            cout << ((temp + s[i] - '0') / d);
            pos++;
            temp = ((temp + s[i] - '0') % d) * 10;
        }
    }
    if(pos == 0) cout << "0";
    // else for(int i = 0; i < pos; i++) cout << ans[i];
    cout << " " << temp / 10;
    return 0;
}