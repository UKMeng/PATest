#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool isPrime(string slice) {
    int temp = stoi(slice);
    for(int i = 2; i < sqrt(temp); i++) {
        if(temp % i == 0) return false;
    }
    return true;
}
int main() {
    int l, k;
    cin >> l >> k;
    string num;
    cin >> num;
    bool flag = false;
    string slice;
    for(int i = 0; i <= l - k; i++) {      
        slice = num.substr(i, k);
        flag = isPrime(slice);
        if(flag) break;
    }
    if(flag) cout << slice << endl;
    else cout << "404" << endl;
    return 0;
}