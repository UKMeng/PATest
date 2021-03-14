// 最后一个测试点浮点数错误
#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long ans1, ans2, temp1, temp2;
void fracSum(long long a1, long long a2, long long b1, long long b2) {
    ans1 = a1 * b2 + b1 * a2;
    ans2 = a2 * b2;
}
void interpret(string s, bool flag){
    int pos;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '/') {
            pos = i;
            break;
        }
    }
    string a, b;
    a = s.substr(0, pos);
    b = s.substr(pos + 1, s.length()-1);
    // cout << a << b << endl;
    if(flag) {
        ans1 = stoll(a);
        ans2 = stoll(b);
    } else{
        temp1 = stoll(a);
        temp2 = stoll(b);
    }
}
long long gcd(long long a, long long b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
void output(long long ans1, long long ans2) {
    long long inter = ans1 / ans2;
    long long yu = ans1 % ans2;
    if(inter != 0 && yu != 0) {
        cout << inter << " ";
        long long temp = gcd(yu, ans2);
        cout << yu/temp << "/" << ans2/temp << endl;
    } else if(inter != 0 && yu == 0) {
        cout << inter << endl;
    } else if(inter == 0 && yu != 0) {
        long long temp = gcd(yu, ans2);
        cout << yu/temp << "/" << ans2/temp << endl;
    } else cout << '0' << endl;
}
int main(){
    int n;
    vector<string> s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        s.push_back(temp);
    }
    interpret(s[0], true);
    for(int i = 1; i < n; i++){
        interpret(s[i], false);
        fracSum(ans1, ans2, temp1, temp2);
    }
    output(ans1, ans2);
    return 0;
}