#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string add(string a, string b){
    int n = a.size();
    string ret;
    int carry = 0;
    for(int i = n-1; i >= 0; i--){
        int num = (a[i] - '0') + (b[i] - '0') + carry;
        if(num >= 10) {
            carry = 1;
            num = num % 10;
        } else carry = 0;
        ret.push_back('0' + num);
    }
    if(carry != 0) ret.push_back('0' + carry);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    string n;
    int k;
    cin >> n >> k;
    int count = 0;
    while(count < k){
        // cout << n << " " << count << endl;
        string re = n;
        reverse(re.begin(), re.end());
        if(re == n) break;
        else{
            n = add(n, re);
            count++;
        }
    }
    cout << n << endl;
    cout << count << endl;
    return 0;
}