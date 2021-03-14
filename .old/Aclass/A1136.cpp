#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool isPalin(string s1) {
    string s2;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    if(s1 == s2) return true;
    else return false;
}
string add(string s1, string s2) {
    string ans;
    int push = 0, stay = 0;
    for(int i = s1.size() - 1; i >= 0; i--) {
        int temp = (s1[i] - '0') + (s2[i] - '0') + push;
        if(temp >= 10) {
            push = temp / 10;
            stay = temp % 10;
        } else {
            push = 0;
            stay = temp;
        }
        ans.insert(ans.begin(), '0' + stay);
    }
    if(push > 0) ans.insert(ans.begin(), '0' + push);
    return ans;
}
int main() {
    int cnt = 0;
    string now;
    cin >> now;
    if(isPalin(now)) {cout << now << " is a palindromic number."; return 0;}
    while(cnt < 10) {
        string s1 = now, s2 = now;
        reverse(s2.begin(), s2.end());
        now = add(s1, s2);
        cout << s1 << " + " << s2 << " = " << now << endl;
        if(isPalin(now)) {cout << now << " is a palindromic number."; return 0;}
        cnt++;
    } 
    cout << "Not found in 10 iterations.";
    return 0;
}