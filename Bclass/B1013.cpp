#include <iostream>
using namespace std;
const int maxn = 10000010;
bool num[maxn] = {false};
int prime[maxn];
int main() {
    int pcount = 0, m, n, outCount = 0;
    cin >> m >> n;
    for(int i = 2; i < maxn; i++) {
        if(num[i] == false) {
            prime[pcount++] = i;
            if(pcount > n) break;
            for(int j = i + i; j < maxn; j += i) num[j] = true;
        }
    }
    for(int i = m - 1; i < n; i++) {
        cout << prime[i];
        if(++outCount % 10 == 0 && i != n - 1) cout << endl;
        if(outCount % 10 != 0 && i != n - 1) cout << " ";
    }
    return 0;
}