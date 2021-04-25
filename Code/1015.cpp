#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n * 1.0); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int reverseRadix(int n, int radix){
    vector<int> temp;
    while(n){
        temp.push_back(n%radix);
        n /= radix;
    }
    //reverse(temp.begin(), temp.end());
    int ret = 0;
    for(int i = 0; i < temp.size(); i++){
        ret *= radix;
        ret += temp[i];
    }
    return ret;
}

bool isRePr(int n, int radix){
    if(!isPrime(n)) return false;
    int ren = reverseRadix(n, radix);
    //cout << ren;
    return isPrime(ren);
}

int main(){
    int n, radix;
    cin >> n;
    while(n > 0){
        cin >> radix;
        if(isRePr(n, radix)) cout << "Yes" << endl;
        else cout << "No" << endl;
        cin >> n;
    }
}