#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

bool is_prime(int n){
    if(n <= 0) return false;
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    bool flag = false;
    if(is_prime(n)){
        if(is_prime(n-6)){
            cout << "Yes" << endl;
            cout << n-6 << endl;
            flag = true;
        } else if(is_prime(n+6)){
            cout << "Yes" << endl;
            cout << n+6 << endl;
            flag = true;
        }
    }
    if(!flag){
        cout << "No" << endl;
        for(int i = n + 1; i < 0x3f3f3f3f; i++){
            if(is_prime(i) && (is_prime(i-6) || is_prime(i+6))) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}