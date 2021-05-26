#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coin(n);
    unordered_map<int, int> mapp;
    for(int i = 0; i < n; i++){
        cin >> coin[i];
        mapp[coin[i]]++;
    }
    sort(coin.begin(), coin.end());
    for(int i = 0; i < n; i++){
        if(mapp[m - coin[i]]){
            if(coin[i] == m-coin[i] && mapp[coin[i]] == 1) continue;
            cout << coin[i] << " " << m - coin[i] << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}