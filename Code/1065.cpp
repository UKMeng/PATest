#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        long long a, b, c;
        // cin >> a >> b >> c; // 用cin获取输入的数如果非常大，比如2^64-1，会出错，longlong类型的输入建议使用scanf
        scanf("%lld %lld %lld", &a, &b, &c);
        long long d = a + b;
        bool flag = true;
        if(a > 0 && b > 0 && d < 0) flag = true;
        else if(a < 0 && b < 0 && d >= 0) flag = false;
        else if(d > c) flag = true;
        else flag = false;
        cout << "Case #" << i <<": ";
        if(flag) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}