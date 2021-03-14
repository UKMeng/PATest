#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int maxn = 1, n, m;
    bool f2 = false;
    cin >> n;
    for(int i = 2; i <= sqrt(n); i++) {
        int temp = 1, j;
        for(j = 0; j < maxn; j++) temp *= i + j;
        if(n < temp) break;
        if(n % temp == 0) {
            if(!f2) {f2 = true; m = i;}
            bool f = false;
            temp *= i + (j++);
            while(n % temp == 0) {
                f = true;
                maxn++;
                temp *= i + (j++);
            }
            if(f) m = i;
            else m = min(m, i);
        }
    }
    if(!f2) m = n;
    cout << maxn << endl;
    for(int i = 0; i < maxn; i++) {
        if(i != 0) cout << "*";
        cout << m + i;
    }
}