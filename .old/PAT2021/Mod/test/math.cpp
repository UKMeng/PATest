#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int gcd(int a, int b){ // 欧几里得算法，求最大公约数（Greatest Common Divisor）
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){ // 求最小公倍数（Least Common Multiple），不难证明 a*b = lcm * gcd
    return a / gcd(a, b) * b;
}

vector<bool> init_prime(int maxn){  // 初始化一个判断是否是素数的数组, 比多次计算是否是素数要快很多
    vector<bool> ret(maxn+1, true);
    ret[1] = false;
    for(int i = 2; i <= maxn; i++){
        if(ret[i]){
            for(int j = i + i; j <= maxn; j += i){
                ret[j] = false;
            }
        }
    }
    return ret;
}

bool is_prime(int n){ // 判断是否是素数
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n * 1.0); i++){
        if(n % i == 0) return false;
    }
    return true;
}

string change_radix(int n, int radix){ // 改变进制, 仅数字在10进制及以下有效，以上需要用字母表示
    string ret;
    while(n != 0){
        ret.push_back('0' + n % radix);
        n /= radix;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    cout << is_prime(1) << endl;
    cout << is_prime(2) << endl;
    cout << change_radix(2, 2) << endl;
    cout << change_radix(13, 2) << endl;
    vector<bool> is_prime_map = init_prime(100);
    for(int i = 1; i <= 100; i++){
        if(is_prime_map[i]) cout << i << " ";
    }
    cout << endl;
    cout << "-----------" << endl;
    cout << gcd(9, 15) << endl;
    cout << lcm(9, 15) << endl;
    return 0;
}