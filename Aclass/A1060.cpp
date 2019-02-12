#include <iostream>
#include <cstring>
using namespace std;
int n;
int findDot(string &s) {
    int t = s.find('.');
    if(t == -1) return s.length();
    else return t;
}
int main() {
    int dot1, dot2, cnt1 = 0, cnt2 = 0, n1 = 0, n2 = 0;
    string a, b, A, B;
    cin >> n >> a >> b; 
    dot1 = findDot(a);
    dot2 = findDot(b);
    while(a[cnt1] == '0' || a[cnt1] == '.') cnt1++;
    while(b[cnt2] == '0' || b[cnt2] == '.') cnt2++;
    if(dot1 < cnt1) dot1 = dot1 - cnt1 + 1;
    else dot1 = dot1 - cnt1;
    if(dot2 < cnt2) dot2 = dot2 - cnt2 + 1;
    else dot2 = dot2 - cnt2;
    if(cnt1 == a.length()) dot1 = 0;
    if(cnt2 == b.length()) dot2 = 0;
    // cout << dot1 << " " << dot2 << endl;
    while(n1 < n) {
        if(a[cnt1] != '.' && cnt1 < a.length()) A.insert(A.begin() + (n1++), a[cnt1]);
        else if(cnt1 >= a.length()) A.insert(A.begin() + (n1++), '0');
        cnt1++;
    }
    while(n2 < n) {
        if(b[cnt2] != '.' && cnt2 < b.length()) B.insert(B.begin() + (n2++), b[cnt2]);
        else if(cnt2 >= b.length()) B.insert(B.begin() + (n2++), '0');
        cnt2++;
    }
    if(dot1 == dot2 && A == B) cout << "YES 0." << A << "*10^" << dot1;
    else cout << "NO 0." << A << "*10^" << dot1 << " 0." << B << "*10^" << dot2;
    return 0;
}