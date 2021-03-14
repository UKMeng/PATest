#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool is_prime(int a){
    if(a <= 1) return false;
    for(int i = 2; i <= sqrt(a * 1.0); i++){
        if(a % i == 0) return false;
    }
    return true;
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

vector<string> nums;
void find_sum_m(int k, int m, string& s, int sum, int now){
    if(now == k && sum == m){
        nums.push_back(s);
        return;
    }
    if(sum + (k - now) * 9 < m) return;
    if(now == 0){
        for(int i = 1; i <= 9; i++){
            if(sum + i > m) return;
            sum += i;
            s.push_back('0' + i);
            find_sum_m(k, m, s, sum, now+1);
            sum -= i;
            s.pop_back();
        }
    } else{
        for(int i = 0; i <= 9; i++){
            if(sum + i > m) return;
            sum += i;
            s.push_back('0' + i);
            find_sum_m(k, m, s, sum, now+1);
            sum -= i;
            s.pop_back();
        }
    }
}

unordered_map<string, int> mapp;
vector<string> ans;
void check(string n, int m){
    long long num = stoll(n);
    string s_1 = to_string(num+1);
    int sum = 0;
    for(int i = 0; i < s_1.size(); i++){
        sum += s_1[i] - '0';
    }
    int gg = gcd(sum, m);
    if(gg > 2 && is_prime(gg)) {
        ans.push_back(n);
        mapp[n] = sum;
    }
}

bool cmp(string a, string b){
    if(mapp[a] != mapp[b]) return mapp[a] < mapp[b];
    else return a < b;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case " << i << endl;
        int k, m;
        cin >> k >> m;
        nums.clear();
        mapp.clear();
        ans.clear();
        string temp;
        find_sum_m(k, m, temp, 0, 0);
        if(nums.size() == 0) {
            cout << "No Solution" << endl;
            continue;
        }
        for(int j = 0; j < nums.size(); j++){
            //cout << nums[j];
            check(nums[j], m);
        }
        if(ans.size() == 0){
            cout << "No Solution" << endl;
            continue;
        } else{
            sort(ans.begin(), ans.end(), cmp);
            for(int j = 0; j < ans.size(); j++){
                cout << mapp[ans[j]] << " " << ans[j] << endl;
            }
        }
    }
    return 0;
}