#include <iostream>
using namespace std;
int main(){
    int n, floor_now = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp > floor_now) ans += (temp - floor_now) * 6 + 5;
        else ans += (floor_now - temp) * 4 + 5;
        floor_now = temp;
    }
    cout << ans;
    return 0;
}