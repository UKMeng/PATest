#include <iostream>
using namespace std;
long long a, b, c, d;
long long gcd(long long x, long long y) {return y == 0 ? x : gcd(y, x % y);}
void pack(long long x, long long y) {
    bool ne = false, inte = false;
    if(y == 0) {cout << "Inf"; return;}
    if(x == 0) {cout << "0"; return;}
    if(x < 0) {ne = true; x = -x;}
    if(y < 0) {
        if(ne) {ne = false;}
        else {ne = true;}
        y = -y;
    }
    if(ne) {cout << "(-";}
    if(x > y) {cout << x / y; x -= y * (x / y); inte = true;}
    if(x == y) {cout << "1"; x = 0;}
    if(x > 0) {
        if(inte) cout << " ";
        int g = gcd(y, x);
        cout << x/g << "/" << y/g;
    }
    if(ne) cout << ")";
}
int main() {
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    pack(a, b); cout << " + "; pack(c, d); cout << " = "; pack(a * d + b * c, b * d); cout << endl;
    pack(a, b); cout << " - "; pack(c, d); cout << " = "; pack(a * d - b * c, b * d); cout << endl;
    pack(a, b); cout << " * "; pack(c, d); cout << " = "; pack(a * c, b * d); cout << endl;
    pack(a, b); cout << " / "; pack(c, d); cout << " = "; pack(a * d, b * c); cout << endl;
    return 0;
}