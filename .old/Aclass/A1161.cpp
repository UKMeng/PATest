#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<string, int> DATA;
map<string, string> NEXT;
int main() {
    string a, b;
    int n;
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++) {
        string address, next;
        int data;
        cin >> address >> data >> next;
        DATA[address] = data;
        NEXT[address] = next;
    }
    vector<string> l, s, temp, ans;
    while(a != "-1") {
        l.push_back(a);
        a = NEXT[a];
    } 
    while(b != "-1") {
        s.push_back(b);
        b = NEXT[b];
    }
    if(l.size() < s.size()) {temp = s; s = l; l = temp;}
    for(int i = 0; i < l.size(); i ++) {
        ans.push_back(l[i]);
        if(!s.empty() && (i + 1) % 2 == 0) { 
            ans.push_back(s.back());
            s.pop_back();
        }
    } 
    while(!s.empty()) {
        ans.push_back(s.back());
        s.pop_back();
    }
    for(int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " " << DATA[ans[i]] << " " << ans[i + 1] << endl;
    } cout << ans[n - 1] << " " << DATA[ans[n - 1]] << " -1" << endl;
    return 0;
}