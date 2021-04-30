#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string multiply(string num){
    int c = 0;
    string ret;
    reverse(num.begin(), num.end());
    for(int i = 0; i < num.length(); i++){
        int k = num[i] - '0';
        if(k < 5) {
            k = k * 2 + c;
            ret.push_back('0' + k);
            c = 0;
        }
        else {
            k = k * 2 - 10 + c;
            ret.push_back('0' + k);
            c = 1;
        }
    }
    if(c == 1) ret.push_back('1');
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    string num;
    cin >> num;
    string doubleNum = multiply(num);
    string ans = doubleNum;
    sort(num.begin(), num.end());
    sort(doubleNum.begin(), doubleNum.end());
    if(num == doubleNum) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << ans << endl;
    return 0;
}