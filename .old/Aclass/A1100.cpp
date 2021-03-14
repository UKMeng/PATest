#include <iostream>
#include <map>
#include <cstring>
using namespace std;
string mar_num[25] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> nm;
void init() {
    for(int i = 0; i < 13; i++) nm[mar_num[i]] = i;
    for(int i = 10; i < 130; i += 10) nm[mar_num[i / 10 + 12]] = i / 10 * 13;
}
void etom(string s) {
    int a = stoi(s);
    if(a >= 13) {
        cout << mar_num[a/13 + 12];
        a = a % 13;
        if(a == 0) {cout << endl; return;}
        cout << " ";
    }
    cout << mar_num[a] << endl;
}
void mtoe(string s) {
    int pos = s.find(' ');
    if(pos == -1)  cout << nm[s] << endl;
    else {
        string s1, s2;
        s1.insert(s1.begin(), s.begin(), s.begin() + pos);
        s2.insert(s2.begin(), s.begin() + pos + 1, s.end());
        cout << nm[s1] + nm[s2] << endl;
    }
}
int main() {
    init();
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if(s[0] >= '0' && s[0] <= '9') etom(s);
        else mtoe(s);
    }
    return 0;
}