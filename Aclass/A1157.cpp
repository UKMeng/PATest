#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int main() {
    set<string> alumni;
    int n, k, cnt = 0;
    string temp, oldid = "9999999999999999";
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        alumni.insert(temp);
    }
    scanf("%d", &k);
    while(k--) {
        cin >> temp;
        if(alumni.count(temp)) {
            cnt++;
            if(cnt == 0 || temp.substr(6, 8) < oldid.substr(6,8)) oldid = temp;
        } else {
            if(cnt == 0 && temp.substr(6, 8) < oldid.substr(6,8)) oldid = temp;
        }
    }
    cout << cnt << endl << oldid << endl;
    return 0;
}