#include <iostream>
using namespace std;
bool isPrime(int a) {
    if(a < 2) return false;
    for(int i = 2; i * i <= a; i++) if(a % i == 0) return false;
    return true;
}
bool table[10010];
int main() {
    int ms, n;
    cin >> ms >> n;
    while(!isPrime(ms)) ms++;
    for(int i = 0; i < n; i++) {
        if(i != 0) cout << " ";
        int temp;
        cin >> temp;
        temp = temp % ms;
        if(!table[temp]) {table[temp] = true; cout << temp;}
        else {
            bool f = false;
            for(int step = 1; step < ms; step++) {      // Quadratic probing
                int t = (temp + step * step) % ms;
                if(!table[t]) {table[t] = true; cout << t; f = true; break;}
            }
            if(!f) cout << "-";
        }
    }
    return 0;
}