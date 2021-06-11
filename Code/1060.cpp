#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<string, int> getPair(string str, int n){
    //
    string tempStr;
    int expo;
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