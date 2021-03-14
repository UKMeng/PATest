#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int change_radix_and_reverse(int k, int d){
    vector<int> temp;
    while(k > 0){
        temp.push_back(k % d);
        k = k / d;
    }
    int ret = 0;
    reverse(temp.begin(), temp.end());
    int p = 1;
    for(int i = 0; i < temp.size(); i++){
        ret += temp[i] * p;
        p *= d;
    }
    return ret;
}

int main(){
    int k, d;
    cin >> k;
    while(k >= 0){
        cin >> d;
        if(!is_prime(k)) {
            cout << "No" << endl;
        } else{ // 进制转换
            int b = change_radix_and_reverse(k, d);
            if(is_prime(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cin >> k;
    }
    return 0;
}