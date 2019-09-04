#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool isPrime(string s) {
    int a = stoi(s);
    if(a <= 1) return false;
    int sqr = (int)sqrt(a);
    for(int i = 2; i < sqr + 1; i++) {
        if(a % i == 0) return false;
    }
    return true;
}
int main() {
    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;
    bool flag = false;
    for(int i = 0; i < n - k + 1; i++) {
        string slice = num.substr(i, k);
        if(isPrime(slice)) {
            cout << slice;
            flag = true;
            break;
        }
    }
    if(!flag) cout << "404";
    return 0;
}