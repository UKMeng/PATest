#include <iostream>
using namespace std;
const int maxn = 100000;
int prime[maxn], factor[maxn], expon[maxn];
bool isPrime[maxn];
int main() {
    int n, pn = 0, fn = 0;
    cin >> n;
    cout << n << "=";
    if(n == 1) {cout << "1"; return 0;}
    for(int i = 2; i <= maxn; i++) {
        if(!isPrime[i]) {
            prime[pn++] = i;
            for(int j = i + i; j <= maxn; j += i) {
                isPrime[j] = true;
            }
        }
    }
    for(int i = 0; i < pn; i++) {
        if(n == 1) break;
        if(n % prime[i] == 0) {
            int cnt = 0;
            while(n % prime[i] == 0) {
                cnt++;
                n /= prime[i];
            }
            factor[fn] = prime[i];
            expon[fn++] = cnt;
        }
    }
    for(int i = 0; i < fn; i++) {
        if(i != 0) cout << "*";
        if(expon[i] > 1) cout << factor[i] << "^" << expon[i];
        else cout << factor[i];
    }
    return 0;
}