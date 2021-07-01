#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    string empty = "";
    vector<string> word;
    unordered_map<string, int> mapp;
    for(int i = 0; i < str.size(); i++){
        if(isalnum(str[i])){
            if(isalpha(str[i]) && isupper(str[i])){
                empty.push_back('a' + (str[i] - 'A'));
            } else{
                empty.push_back(str[i]);
            }
        } else{
            if(empty.size() != 0) {
                if(mapp.count(empty) == 0){
                    mapp[empty] = 1;
                    word.push_back(empty);
                } else{
                    mapp[empty]++;
                }
                // cout << empty << endl;
                empty.clear();
            }
        }
    }
    if(empty.size() != 0) {    // "a"的时候直接退出循环了，要么这样多写几行，要么就改变循环的逻辑，先判断字符是不是换行符
        if(mapp.count(empty) == 0){
            mapp[empty] = 1;
            word.push_back(empty);
        } else{
            mapp[empty]++;
        }
        // cout << empty << endl;
        empty.clear();
    }
    int maxn = 0;
    string ans = "";
    for(int i = 0; i < word.size(); i++){
        if(mapp[word[i]] > maxn){
            maxn = mapp[word[i]];
            ans = word[i];
        }
    }
    cout << ans << " " << maxn << endl;
    return 0;
}