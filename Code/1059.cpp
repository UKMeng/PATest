#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

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

int main(){
    long long n;
    cin >> n;
    if(n == 1){
        cout << "1=1";
        return 0;
    }
    vector<int> prime, ans;
    unordered_map<int, int> ansNum;
    vector<bool> initPrime = init_prime(100000);
    for(int i = 1; i <= 100000; i++){
        if(initPrime[i]) prime.push_back(i);
    }
    int index = 0;
    long long temp = n;
    bool flag = true;
    while(n != 1){
        if(n % prime[index] == 0){
            n /= prime[index];
            if(flag) {
                ans.push_back(prime[index]);
                flag = false;
            }
            ansNum[prime[index]]++;
        } else{
            index++;
            flag = true;
        }
    }
    cout << temp << "=";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(ansNum[ans[i]] != 1){
            cout << "^" << ansNum[ans[i]];
        }
        if(i != ans.size() - 1) cout << "*";
    }
    return 0;
}