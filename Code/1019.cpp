#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num, radix;
    cin >> num >> radix;
    vector<int> tran;
    while(num > 0){
        tran.push_back(num%radix);
        num /= radix;
    }
    vector<int> ans = tran;
    reverse(ans.begin(), ans.end());
    if(ans == tran) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    return 0;
}