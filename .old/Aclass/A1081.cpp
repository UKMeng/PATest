#include <iostream>
using namespace std;
long long num[110], den[110];
long long ansn, ansd;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b);}
void cal(int a) {
    if(ansd == den[a]) {ansn = ansn + num[a];}
    else if(ansd > den[a]) {
        if(ansd % den[a] == 0) {ansn = ansn + num[a] * (ansd / den[a]);}
        else {
            ansn = ansn * den[a] + num[a] * ansd;
            ansd = ansd * den[a];
        }
    }
    else {
        if(den[a] % ansd == 0) {
            ansn = ansn * (den[a] / ansd) + num[a];
            ansd = den[a];
        }
        else {
            ansn = ansn * den[a] + num[a] * ansd;
            ansd = ansd * den[a];
        }
    }
}
int main() {
    int n;
    cin >> n;
    scanf ("%lld/%lld", &num[0], &den[0]);
    ansn = num[0], ansd = den[0];
    for(int i = 1; i < n; i++) {
        scanf ("%lld/%lld", &num[i], &den[i]);
        // cout << num[i] << "/" << den[i] << endl;
        cal(i);
        // cout << ansn << "/" << ansd << endl;
    }
    if(ansn == 0) {cout << ansn;}
    if(ansn < 0) {cout << "-"; ansn = -ansn;}
    if(ansn >= ansd) {cout << ansn / ansd; ansn = ansn - ansd * (ansn / ansd); n = -1;}
    if(ansn > 0) {
        if(n == -1) cout << " ";
        long long d = gcd(ansd, ansn);
        cout << ansn / d << "/" << ansd / d;
    }
    return 0;
}