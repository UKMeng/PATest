#include <iostream>
using namespace std;
int main() {
    int query;
    cin >> query;
    long long a, b, c;
    bool flag;
    for(int i = 0; i < query; i++) {
        cin >> a >> b >> c;
        long long d = a + b;
        if(a > 0 && b > 0 && d < 0) flag = true;
        else if(a < 0 && b < 0 && d >= 0) flag = false;
        else if(d > c) flag = true;
        else flag = false;
        cout << "Case #" << i + 1 << ": ";
        if(flag) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}