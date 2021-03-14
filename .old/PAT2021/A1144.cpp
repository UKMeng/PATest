#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, int> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        m[temp]++;
    }
    int num = 0;
    while(++num){
        if(m[num] == 0) {
            cout << num;
            break;
        }
    }
    return 0;
}