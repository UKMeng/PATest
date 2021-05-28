#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    unordered_map<char, bool> mapp;
    for(int i = 0; i < s2.size(); i++){
        mapp[s2[i]] = true;
    }
    string ans;
    for(int i = 0; i < s1.size(); i++){
        if(!mapp[s1[i]]){
            ans.push_back(s1[i]);
        }
    }
    cout << ans << endl;
    return 0;
}