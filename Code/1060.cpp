#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<string, int> getPair(string str, int n){
    //
    string tempStr;
    int expo;
    if(str.find('.') == -1) expo = str.length();
    else expo = str.find('.');
    int pos = 0;
    bool flag = true;
    for(; pos < str.size(); pos++){
        if(str[pos] == '.') continue;
        if(str[pos] != '0') {
            flag = false;
            break;
        }
        expo--;
    }
    if(flag) expo = 0;
    for(; pos < str.size(); pos++){
        if(tempStr.size() == n) break;
        if(str[pos] != '.') tempStr.push_back(str[pos]);
    }
    if(tempStr.size() < n){
        int l = tempStr.size();
        for(int i = 0; i < n - l; i++){
            tempStr.push_back('0');
        }
    }
    return make_pair(tempStr, expo);
}

int main(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    pair<string, int> ansA = getPair(a, n);
    pair<string, int> ansB = getPair(b, n);
    if(ansA.first == ansB.first && ansA.second == ansB.second){
        cout << "YES 0." << ansA.first << "*10^" << ansA.second;
    } else{
        cout << "NO 0." << ansA.first << "*10^" << ansA.second << " 0." << ansB.first << "*10^" << ansB.second;
    }
    return 0;
}