#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    unordered_map<int, int> mapp;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        mapp[num[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(mapp[num[i]] == 1) {
            cout << num[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}