#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool check(vector<int> num, int m, int n){
    stack<int> stk;
    int popNumIndex = 0, pushNum = 1;
    bool isPossible = true;
    while(popNumIndex < n){
        if(num[popNumIndex] >= pushNum){
            if(stk.size() < m){
                stk.push(pushNum);
                pushNum++;
            } else{
                isPossible = false;
                break;
            }
        } else{
            if(num[popNumIndex] == stk.top()){
                stk.pop();
                popNumIndex++;
            } else{
                isPossible = false;
                break;
            }
        }
    }
    return isPossible && stk.empty();
}

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    while(k--){
        vector<int> temp(n);
        for(int i = 0; i < n; i++) scanf("%d", &temp[i]);
        if(check(temp, m, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}