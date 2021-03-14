#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> panda(n);
    for(int i = 0; i < n; i++) {cin >> panda[i];}
    vector<int> milk(n);
    milk[0] = 200;
    for(int i = 1; i < n; i++){
        if(panda[i] > panda[i-1]){
            milk[i] = milk[i-1] + 100;
        } else if(panda[i] == panda[i-1]){
            milk[i] = milk[i-1];
        } else{
            milk[i] = 200;
            for(int j = i-1; j >= 0; j--){
                if(panda[j+1] < panda[j] && milk[j+1] == milk[j]){
                    milk[j] += 100; 
                } else if(panda[j+1] == panda[j] && milk[j+1] > milk[j]){
                    milk[j] += 100;
                } else{
                    break;
                }
            }
        }
    }
    int ans = 0;
    for(auto num:milk) ans += num;
    cout << ans;
    return 0;
}