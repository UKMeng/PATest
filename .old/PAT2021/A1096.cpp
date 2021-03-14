#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 有漏洞，测试点4过不去
int main(){
    int n;
    cin >> n;
    vector<int> factor;
    for(int i = 2; i < sqrt(n) + 1; i++){
        if(n % i == 0) factor.push_back(i);
    }
    if(factor.size() == 0){  // 质数
        cout << "1" << endl;
        cout << n << endl;
        return 0;
    }
    // 寻找factor数组中的最长序列且其元素乘积不得大于n
    vector<int> ans;
    vector<int> temp{factor[0]};
    int multi;
    for(int i = 0; i < factor.size(); i++){
        if(temp.back() + 1 == factor[i]){
            if(multi * factor[i] <= n) {
                multi = multi * factor[i];
                temp.push_back(factor[i]);
            } else{
                if(ans.size() < temp.size()){
                    ans = temp;
                    temp.clear();
                    break;
                }
            }
        } else{
            if(ans.size() < temp.size()){
                ans = temp;
            }
            temp.clear();
            temp.push_back(factor[i]);
            multi = factor[i];
        }
    }
    if(ans.size() < temp.size()){
        ans = temp;
    }       
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) cout << "*" << ans[i];
        else cout << ans[i];
    }
    return 0;
}