#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) cin >> num[i];
    int ans = n * 5;
    int now = 0;
    for(int i = 0; i < n; i++){
        if(num[i] > now){
            ans += (num[i] - now) * 6;
            now = num[i];
        } else{
            ans += (now - num[i]) * 4;
            now = num[i];
        }
    }
    cout << ans;
    return 0;
}