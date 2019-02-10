#include <iostream>
using namespace std;
bool isPrime[100010] = {false};
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i] == false) {
            if(!isPrime[i] && !isPrime[i-2] && i > 4) ans++;
            for(int j = i + i; j < n; j += i) isPrime[j] = true;
        }
    }
    cout << ans;
    return 0;
}