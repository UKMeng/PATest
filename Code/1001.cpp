#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    string c = to_string(a + b);
    string ans;
    int count = 0;
    for(int i = c.size()-1; i >= 0; i--){
        ans.push_back(c[i]);
        count++;
        if(count == 3 && i != 0 && c[i-1] != '-'){
            ans.push_back(',');
            count = 0;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}