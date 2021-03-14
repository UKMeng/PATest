#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> prime;
vector<bool> prime_map;
vector<bool> init(int k){
    vector<bool> temp(k+1, true);
    temp[1] = false;
    for(int i = 2; i <= k; i++){
        if(temp[i]){
            prime.push_back(i);
            for(int j = i + i; j <= k; j += i){
                temp[j] = false;
            }
        }
    }
    return temp;
}

int main(){
    int n, k;
    cin >> n >> k;
    prime_map = init(k);
    int ans = 0;
    int difans = 0;
    for(int i = 0; i < prime.size(); i++){
        int dif;
        int count;
        for(int j = i + 1; j < prime.size(); j++){
            count = 2;
            dif = prime[j] - prime[i];
            int now = dif + prime[j];
            for(int c = 3; c <= n; c++){
                if(now <= k && prime_map[now]){
                    now += dif;
                    count++;
                } else{
                    break;
                }
            }
            if(count == n){
                if(dif >= difans) {
                    difans = dif;
                    ans = prime[i];
                }
            }            
        }
    }
    if(ans == 0) cout << prime.back() << endl;
    else{
        for(int i = 0; i < n; i++){
            if(i != 0) cout << " " << ans;
            else cout << ans;
            ans += difans;
        }
    }
    return 0;
}