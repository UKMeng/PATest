#include <iostream>
using namespace std;
bool isPrime(int a) {
    if(a < 2) return false;
    for(int i = 2; i * i < a; i++) if(a % i == 0) return false;
    return true;
}
int main() {
    int n, d, f = 0;
    while(1) {
        cin >> n;
        if(n < 0) break;
        cin >> d;
        if(f == 0) f++;
        else cout << endl;
        if(!isPrime(n)) cout << "No";
        else if(isPrime(n)) {
            int cnt = 0, num[100];
            while(n) {
                num[cnt++] = n % d;
                n /= d;
            }
            for(int i = 0; i < cnt; i++) n = n * d + num[i];
            if(!isPrime(n)) cout << "No";
            else cout << "Yes";
        }
    }
    return 0;
}